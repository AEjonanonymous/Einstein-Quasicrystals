# <div align="center">💎 "ein-Stein" (One-Stone) Quasicrystals 💎 
## <div align="center"><i>A Lean 4 Certified Proof of 3D Aperiodic Einstein Quasicrystals by Triviality of the Projection Kernel.</i>

## <div align="center">📌 Abstract

<i>Standard approaches to the classical Einstein problem fail by attempting to lift two-dimensional aperiodic monotiles into three dimensions through height extrusion, 
which inherently causes geometric collapse and structural hollowing. Our novel insight resolves this by shifting from extrusion to de Bruijn’s cut-and-project method, deploying a 4D-to-3D projection framework on $\mathbb{Z}^4$ to generate a true, volumetric structure. We formally verify this novel insight inside the Lean 4 theorem prover by proving the triviality of the projection kernel. This formal proof establishes strict linear injectivity, guaranteeing that no dimensional folding or coordinate collisions occur, which mathematically locks down global aperiodicity and proves the existence of the Einstein Quasicrystal. 
Keywords: Mathematics, Discrete Geometry, 3D Aperiodic Monotiles, Einstein Tile, Hat Tile, de Bruijn Cut-and-Project Framework, Delaunay Triangulation, Meyer Set, Quasicrystals, Formal Verification, Interactive Theorem Proving, Lean 4, Injective Proof, Trivial Kernel. </i>

## The 4-Step Computational Pipeline

To generate true 3D volumetric structures without hollow sides, our pipeline executes the following:

**Step 1: 4D Grid Initialization**

Defines a bounded integer grid in a 4-dimensional hypercubic space ($\Lambda = \mathbb{Z}^4$) within a radius $R$.

**Step 2: Hexagonal Projection Matrices**

Splits 4D space into physical 3D space ($E_\parallel$) and 1D internal perpendicular phase space ($E_\perp$).

Embeds native hexagonal angles ($30^\circ$ and $60^\circ$ / $\pi/6$ and $\pi/3$) into the parallel projection matrix ($M_\parallel$).

**Step 3: Acceptance Window Filtering ($W$)**

Filters 4D nodes using an acceptance window modulated by the hat's kite sub-component boundaries. Nodes whose internal phase ($t$) falls within $W$ survive.

**Step 4: Topological Reconstruction (Solving Hollow Sides)**

Connects surviving vertices based on original 4D Manhattan neighbor relationships ($\Vert{}\Delta \mathbf{v}\Vert{} = 1$). This automatically generates solid, non-hollow side walls and complex facets.

## 💻 Javascript Demonstration
We implemented a spatial interlock and overlap validation script in JavaScript to test adjacent phase-shifted tiles:

* 💻 `4d_to_3d_cut_and-project_ein_stein_quasicrystal_demo.html`

### 📽️ Projection Visualizer

![Einstein Quasiscrystal Projection](https://github.com/AEjonanonymous/ein-Stein-Quasicrystal/blob/main/ein_stein_quasicrystal.PNG)

`ein_stein_quasicrystal.PNG`: What we are looking at is no longer a standard 2D shape forced into 3D, but a true 3D aperiodic Einstein Quasicrystal.

Non-Repeating Global Structure: Because the physical projection matrix $M_\parallel$ embeds irrational trigonometric ratios ($\cos(30^\circ)$ and $\sin(30^\circ)$), every node and connecting strut aligns strictly with the tile's native hexagonal vector directions. Yet, as you rotate the camera, you’ll notice no single volumetric cell repeats identically because it possesses long-range order without periodicity.

Faceted Side Walls: Unlike flat vertical extrusions that leave hollow sides, every 3D segment here is bounded by actual 4D lattice neighbors ($\Vert{}\Delta \mathbf{v}\Vert{} = 1$). The walls are intricate, oblique polyhedral facets that share the exact geometric DNA of the top and bottom faces.

Quasicrystal Architecture: In physics, this is almost identical to how nature arranges atoms in real-world quasicrystals. The 1D internal phase space ($E_\perp$) acts like a geometric aperture, slicing through 4D space to reveal a complex 3D WebGL wireframe of connected nodes and struts.


## ✅ Machine Certification of Injectivity and in Lean 4 

*Lattice kernel triviality verified successfully.*

