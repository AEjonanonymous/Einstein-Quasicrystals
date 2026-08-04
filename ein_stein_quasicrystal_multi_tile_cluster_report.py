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

def generate_tile_nodes(phase_offset=0.0, spatial_translation=np.array([0.0, 0.0, 0.0]), range_r=3):
    nodes = []
    for x in range(-range_r, range_r + 1):
        for y in range(-range_r, range_r + 1):
            for z in range(-range_r, range_r + 1):
                for w in range(-range_r, range_r + 1):
                    v = np.array([x, y, z, w], dtype=float)
                    t = compute_internal_phase(v) + phase_offset
                    if -1.2 <= t <= 1.2:
                        pos3d = project4_to_3d(v) + spatial_translation
                        nodes.append(pos3d)
    return np.array(nodes)

def validate_cluster(tiles, tolerance=0.001, contact_max=0.35):
    total_collisions = 0
    total_contacts = 0
    num_tiles = len(tiles)
    
    # Check every unique pair of tiles in the cluster
    for i in range(num_tiles):
        for j in range(i + 1, num_tiles):
            posA = tiles[i]
            posB = tiles[j]
            
            for pA in posA:
                dists = np.linalg.norm(posB - pA, axis=1)
                total_collisions += np.sum(dists < tolerance)
                total_contacts += np.sum((dists > 0) & (dists < contact_max))
                
    return total_collisions, total_contacts

if __name__ == "__main__":
    print("Initializing Multi-Tile Cluster Pipeline...")
    
    # Define a cluster of tiles with different phases and 3D layout vectors
    cluster = [
        generate_tile_nodes(phase_offset=0.00, spatial_translation=np.array([0.0, 0.0, 0.0])),
        generate_tile_nodes(phase_offset=0.85, spatial_translation=np.array([2.5, 1.0, 0.0])),
        generate_tile_nodes(phase_offset=1.70, spatial_translation=np.array([1.25, 3.2, 0.0]))
    ]
    
    collisions, contacts = validate_cluster(cluster)
    
    print("\n--- MULTI-TILE CLUSTER REPORT ---")
    print(f"Total Tiles in Cluster: {len(cluster)}")
    print(f"Cluster Collisions:     {collisions} {'(PASS)' if collisions == 0 else '(FAIL)'}")
    print(f"Total Contact Points:   {contacts}")
    print(f"Cluster Status:         {'STABLE PATCH!' if collisions == 0 else 'COLLISION DETECTED'}")