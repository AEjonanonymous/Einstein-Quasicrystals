import numpy as np

THETA = np.pi / 6
COS_T = np.cos(THETA)
SIN_T = np.sin(THETA)

def project4_to_3d(v):
    x = v[0] + v[1] * COS_T - v[3] * SIN_T
    y = v[1] * SIN_T + v[2] + v[3] * COS_T
    z = v[0] * 0.587 + v[2] * 0.587 - v[3] * 0.707
    return np.array([x, y, z])

def compute_internal_phase(v):
    return -v[0] * SIN_T + v[1] * COS_T - v[2] * SIN_T + v[3] * COS_T

def generate_tile_nodes(phase_offset=0.0, range_r=3):
    nodes = []
    for x in range(-range_r, range_r + 1):
        for y in range(-range_r, range_r + 1):
            for z in range(-range_r, range_r + 1):
                for w in range(-range_r, range_r + 1):
                    v = np.array([x, y, z, w], dtype=float)
                    # True cut-and-project phase window shift
                    t = compute_internal_phase(v) + phase_offset
                    
                    if -1.2 <= t <= 1.2:
                        nodes.append(project4_to_3d(v))
    return np.array(nodes)

def validate_tiling(posA, posB, tolerance=0.001, contact_max=0.35):
    collisions = 0
    contacts = 0
    for pA in posA:
        dists = np.linalg.norm(posB - pA, axis=1)
        collisions += np.sum(dists < tolerance)
        contacts += np.sum((dists > 0) & (dists < contact_max))
    return collisions, contacts

if __name__ == "__main__":
    posA = generate_tile_nodes(phase_offset=0.0, range_r=3)
    posB = generate_tile_nodes(phase_offset=0.85, range_r=3) # True 4D phase slice
    
    print(f"Tile A Nodes: {len(posA)} | Tile B Nodes: {len(posB)}")
    collisions, contacts = validate_tiling(posA, posB)
    print(f"Overlap Collisions: {collisions} | Contact Points: {contacts}")