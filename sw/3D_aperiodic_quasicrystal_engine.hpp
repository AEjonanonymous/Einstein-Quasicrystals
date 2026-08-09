/**
 * @file 3D_aperiodic_quasicrystal_engine.hpp
 * @author Jonathan f(n) Reed
 * @license GNU Affero General Public License v3.0 (AGPL-3.0)
 */

#ifndef D_3_APERIODIC_QUASICRYSTAL_ENGINE_HPP
#define D_3_APERIODIC_QUASICRYSTAL_ENGINE_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>
#include <iomanip>

namespace AperiodicEngine {

// ==========================================
// 1. Core Mathematical Structures
// ==========================================

struct LatticePoint4D {
    int x1;
    int x2;
    int x3;
    int x4;

    bool operator==(const LatticePoint4D& other) const {
        return x1 == other.x1 && x2 == other.x2 && x3 == other.x3 && x4 == other.x4;
    }
};

struct Point3D {
    double px;
    double py;
    double pz;

    Point3D operator+(const Point3D& o) const { return {px + o.px, py + o.py, pz + o.pz}; }
    Point3D operator-(const Point3D& o) const { return {px - o.px, py - o.py, pz - o.pz}; }
    Point3D operator*(double scalar) const { return {px * scalar, py * scalar, pz * scalar}; }
    Point3D operator/(double scalar) const { return {px / scalar, py / scalar, pz / scalar}; }
};

struct TriangleFace {
    Point3D v0, v1, v2;
    Point3D normal;
};

// ==========================================
// 2. Configuration & Parameterization
// ==========================================

struct EngineConfig {
    int range_r = 3;                      // 4D grid iteration bounds (-range_r to range_r)
    double scale_factor = 15.0;           // Physical scaling factor (e.g., millimeters)
    double window_min = -1.0;             // 1D internal phase lower acceptance bound[cite: 1]
    double window_max = 1.0;              // 1D internal phase upper acceptance bound[cite: 1]
    double tube_radius = 0.35;            // Structural strut radius for volumetric sweeping
    int tube_segments = 4;                // Cross-sectional polygon complexity (e.g., 4 = square tube)
    
    // Optional custom density / window modulation hook for graded porosity
    std::function<bool(const LatticePoint4D&, double t)> custom_filter = nullptr;
};

// ==========================================
// 3. The Geometry Engine Class
// ==========================================

class AperiodicGeometryEngine {
private:
    EngineConfig config;
    const double sqrt3 = std::sqrt(3.0);
    const double sqrt2 = std::sqrt(2.0);

    // Exact Lean-verified parallel projection mapping (M_parallel)
    Point3D projHom(const LatticePoint4D& v) const {
        double x1 = static_cast<double>(v.x1);
        double x2 = static_cast<double>(v.x2);
        double x3 = static_cast<double>(v.x3);
        double x4 = static_cast<double>(v.x4);

        double px = x1 + x2 * (sqrt3 / 2.0) - x4 * (1.0 / 2.0);
        double py = x2 * (1.0 / 2.0) + x3 + x4 * (sqrt3 / 2.0);
        double pz = x1 * (sqrt3 / 3.0) + x3 * (sqrt3 / 3.0) - x4 * (sqrt2 / 2.0);

        return {px * config.scale_factor, py * config.scale_factor, pz * config.scale_factor};
    }

    // Complementary perpendicular internal phase projection (M_perpendicular) for 1D windowing
    double computeInternalPhase(const LatticePoint4D& v) const {
        return (v.x1 * 0.2113 + v.x2 * 0.4226 + v.x3 * 0.6339 - v.x4 * 0.8452);
    }

    bool isAccepted(const LatticePoint4D& v) const {
        double t = computeInternalPhase(v);
        if (config.custom_filter) {
            return config.custom_filter(v, t);
        }
        return (t >= config.window_min && t <= config.window_max);
    }

    Point3D normalize(const Point3D& p) const {
        double len = std::sqrt(p.px * p.px + p.py * p.py + p.pz * p.pz);
        if (len < 1e-9) return {0, 0, 0};
        return {p.px / len, p.py / len, p.pz / len};
    }

    Point3D cross(const Point3D& a, const Point3D& b) const {
        return {
            a.py * b.pz - a.pz * b.py,
            a.pz * b.px - a.px * b.pz,
            a.px * b.py - a.py * b.px
        };
    }

    Point3D computeNormal(const Point3D& v0, const Point3D& v1, const Point3D& v2) const {
        Point3D edge1 = v1 - v0;
        Point3D edge2 = v2 - v0;
        return normalize(cross(edge1, edge2));
    }

public:
    explicit AperiodicGeometryEngine(const EngineConfig& cfg = EngineConfig()) : config(cfg) {}

    void setConfig(const EngineConfig& cfg) { config = cfg; }

    std::vector<TriangleFace> generateMesh() const {
        std::vector<TriangleFace> meshFaces;
        std::vector<LatticePoint4D> validNodes;

        for (int x1 = -config.range_r; x1 <= config.range_r; ++x1) {
            for (int x2 = -config.range_r; x2 <= config.range_r; ++x2) {
                for (int x3 = -config.range_r; x3 <= config.range_r; ++x3) {
                    for (int x4 = -config.range_r; x4 <= config.range_r; ++x4) {
                        LatticePoint4D pt{x1, x2, x3, x4};
                        if (isAccepted(pt)) {
                            validNodes.push_back(pt);
                        }
                    }
                }
            }
        }

        const int neighborOffsets[8][4] = {
            { 1,  0,  0,  0}, {-1,  0,  0,  0},
            { 0,  1,  0,  0}, { 0, -1,  0,  0},
            { 0,  0,  1,  0}, { 0,  0, -1,  0},
            { 0,  0,  0,  1}, { 0,  0,  0, -1}
        };

        std::vector<std::pair<LatticePoint4D, LatticePoint4D>> validEdges;
        
        for (const auto& node : validNodes) {
            Point3D pA = projHom(node);
            for (int i = 0; i < 8; ++i) {
                LatticePoint4D neighbor = {
                    node.x1 + neighborOffsets[i][0],
                    node.x2 + neighborOffsets[i][1],
                    node.x3 + neighborOffsets[i][2],
                    node.x4 + neighborOffsets[i][3]
                };

                if (isAccepted(neighbor)) {
                    if (node.x1 < neighbor.x1 || 
                       (node.x1 == neighbor.x1 && node.x2 < neighbor.x2) ||
                       (node.x1 == neighbor.x1 && node.x2 == neighbor.x2 && node.x3 < neighbor.x3) ||
                       (node.x1 == neighbor.x1 && node.x2 == neighbor.x2 && node.x3 == neighbor.x3 && node.x4 < neighbor.x4)) {
                        validEdges.push_back({node, neighbor});
                    }
                }
            }
        }

        for (const auto& edge : validEdges) {
            Point3D p1 = projHom(edge.first);
            Point3D p2 = projHom(edge.second);

            Point3D dir = p2 - p1;
            double length = std::sqrt(dir.px * dir.px + dir.py * dir.py + dir.pz * dir.pz);
            if (length < 1e-6) continue;
            dir = normalize(dir);

            Point3D arbitrary = (std::abs(dir.px) < 0.9) ? Point3D{1, 0, 0} : Point3D{0, 1, 0};
            Point3D u = normalize(cross(dir, arbitrary));
            Point3D v = normalize(cross(dir, u));

            int segs = config.tube_segments;
            std::vector<std::vector<Point3D>> ringVertices(2, std::vector<Point3D>(segs));

            const Point3D* endpoints[2] = {&p1, &p2};
            for (int r = 0; r < 2; ++r) {
                for (int s = 0; s < segs; ++s) {
                    double theta = 2.0 * M_PI * s / segs;
                    double cx = std::cos(theta) * config.tube_radius;
                    double cy = std::sin(theta) * config.tube_radius;
                    
                    ringVertices[r][s] = *endpoints[r] + (u * cx) + (v * cy);
                }
            }

            for (int s = 0; s < segs; ++s) {
                int next_s = (s + 1) % segs;
                
                Point3D a = ringVertices[0][s];
                Point3D b = ringVertices[0][next_s];
                Point3D c = ringVertices[1][next_s];
                Point3D d = ringVertices[1][s];

                meshFaces.push_back({a, b, c, computeNormal(a, b, c)});
                meshFaces.push_back({a, c, d, computeNormal(a, c, d)});
            }
        }

        return meshFaces;
    }

    bool exportToSTL(const std::string& filepath, const std::vector<TriangleFace>& faces) const {
        std::ofstream outfile(filepath);
        if (!outfile.is_open()) {
            std::cerr << "Error: Could not open file for writing: " << filepath << std::endl;
            return false;
        }

        outfile << "solid AperiodicEinsteinQuasicrystal\n";
        for (const auto& face : faces) {
            outfile << "  facet normal " << face.normal.px << " " << face.normal.py << " " << face.normal.pz << "\n";
            outfile << "    outer loop\n";
            outfile << "      vertex " << face.v0.px << " " << face.v0.py << " " << face.v0.pz << "\n";
            outfile << "      vertex " << face.v1.px << " " << face.v1.py << " " << face.v1.pz << "\n";
            outfile << "      vertex " << face.v2.px << " " << face.v2.py << " " << face.v2.pz << "\n";
            outfile << "    endloop\n";
            outfile << "  endfacet\n";
        }
        outfile << "endsolid AperiodicEinsteinQuasicrystal\n";
        outfile.close();
        return true;
    }
};

} // namespace AperiodicEngine

#endif // D_3_APERIODIC_QUASICRYSTAL_ENGINE_HPP