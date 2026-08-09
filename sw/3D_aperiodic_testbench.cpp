/**
 * @file 3D_aperiodic_testbench.cpp
 * @author Jonathan f(n) Reed
 * @license GNU Affero General Public License v3.0 (AGPL-3.0)
 */

#include "3D_aperiodic_quasicrystal_engine.hpp"

int main() {
    std::cout << "==================================================\n";
    std::cout << "  3D Aperiodic Quasicrystal Engine Testbench      \n";
    std::cout << "==================================================\n";

    AperiodicEngine::EngineConfig config;
    config.range_r = 3;
    config.scale_factor = 20.0;
    config.window_min = -1.0;
    config.window_max = 1.0;
    config.tube_radius = 0.4;
    config.tube_segments = 4;

    config.custom_filter = [](const AperiodicEngine::LatticePoint4D& pt, double t) {
        return (t >= -1.0 && t <= 1.0);
    };

    AperiodicEngine::AperiodicGeometryEngine engine(config);

    std::cout << "[*] Generating volumetric aperiodic mesh...\n";
    std::vector<AperiodicEngine::TriangleFace> mesh = engine.generateMesh();

    std::cout << "[+] Mesh Generation Complete:\n";
    std::cout << "    - Total Triangle Faces: " << mesh.size() << "\n";

    std::string filename = "generalized_aperiodic_structure.stl";
    std::cout << "[*] Exporting geometry to " << filename << "...\n";
    
    if (engine.exportToSTL(filename, mesh)) {
        std::cout << "[+] Successfully exported manifold solid model!\n";
    } else {
        std::cerr << "[-] Export failed.\n";
    }

    std::cout << "==================================================\n";
    return 0;
}