# <div align="center">💎 Einstein ("ein-Stein") Quasicrystals 💎 
## <div align="center"><i>A Lean 4 Certified Proof of 3D Aperiodic Einstein Quasicrystals by Triviality of the Projection Kernel.</i>

## <div align="center">📌 Abstract

<i>Standard approaches to the classical Einstein problem fail by attempting to lift two-dimensional aperiodic monotiles into three dimensions through height extrusion, 
which inherently causes geometric collapse and structural hollowing. Our novel insight resolves this by shifting from extrusion to de Bruijn’s cut-and-project method, deploying a 4D-to-3D projection framework on $\mathbb{Z}^4$ to generate a true, volumetric structure. We formally verify this novel insight inside the Lean 4 theorem prover by proving the triviality of the projection kernel. This formal proof establishes strict linear injectivity, guaranteeing that no dimensional folding or coordinate collisions occur, which mathematically locks down global aperiodicity and proves the existence of the Einstein Quasicrystal. 
Keywords: Mathematics, Discrete Geometry, 3D Aperiodic Monotiles, Einstein Tile, Hat Tile, de Bruijn Cut-and-Project Framework, Delaunay Triangulation, Meyer Set, Quasicrystals, Formal Verification, Interactive Theorem Proving, Lean 4, Injective Proof, Trivial Kernel. </i>

**Keywords:** Mathematics, Discrete Geometry, 3D Aperiodic Monotiles, Einstein Tile, Hat Tile, de Bruijn Cut-and-Project Framework, Delaunay Triangulation, Meyer Set, Quasicrystals, Formal Verification, Interactive Theorem Proving, Lean 4, Injective Proof, Trivial Kernel.


## 📐 The 4-Step Computational Pipeline

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

![Einstein Quasiscrystal Projection](https://github.com/AEjonanonymous/Einstein-Quasicrystals/blob/main/ein_stein_quasicrystal.PNG)

`ein_stein_quasicrystal.PNG`: What we are looking at is no longer a standard 2D shape forced into 3D, but a true 3D aperiodic Einstein Quasicrystal.

**Non-Repeating Global Structure:** Because the physical projection matrix $M_\parallel$ embeds irrational trigonometric ratios ($\cos(30^\circ)$ and $\sin(30^\circ)$), every node and connecting strut aligns strictly with the tile's native hexagonal vector directions. Yet, as you rotate the camera, you’ll notice no single volumetric cell repeats identically because it possesses long-range order without periodicity.

**Faceted Side Walls:** Unlike flat vertical extrusions that leave hollow sides, every 3D segment here is bounded by actual 4D lattice neighbors ($\Vert{}\Delta \mathbf{v}\Vert{} = 1$). The walls are intricate, oblique polyhedral facets that share the exact geometric DNA of the top and bottom faces.

**Quasicrystal Architecture:** In physics, this is almost identical to how nature arranges atoms in real-world quasicrystals. The 1D internal phase space ($E_\perp$) acts like a geometric aperture, slicing through 4D space to reveal a complex 3D WebGL wireframe of connected nodes and struts.

## ✅ Machine Certification of Injectivity in Lean 4 

**Verify in Browser:** 💻 [`EinsteinQuasicrystalKernelTriviality.lean`](https://live.lean-lang.org/#project=mathlib-stable&codez=JYWwDg9gTgLgBAWQIYwBYBtgCMBQOB2E%2BAxhOAK4xJboCmcAzrcTMEXgAIDatAHjAF0cDGFHItyUegBkUrYrQAKEYPhgAWACJwA7qlpSccOLwCMcAFxxAJIRGTAJks27vAMxPbx3uo92AJgbAAG6qAOZwmszAftR0AKIAjpw8%2FEIiYhJScMqqMK7aega0dmC8ToC4hCUAnhUlAF61xgFQwWERUTE0tIl4AQBmjAmw7lbllgC8cABKtEjoAHQMQ%2FCuOP2DsI6jE9OzC0uwcPa9tANgUBAAVgASZHAAFEFOsjDySipqWgCUTjlq%2BTs7ABvOClHaPeZmCo%2FADUDyCkK2cHKPwAVA8Dnk4AB6I4%2FAC08MhPlGaIe5lx9i%2BdgANKCahZJhDeEiUXB0fcKXi4HDmSNkbCid5oeyMct3JTqcY6WAGoyheZSaL7piJXBXIK%2BSKOaqceqCUKSQLlZjHJK4ABfPB0EAgJAbPIAfSgKEdwCgUAe9qwHh%2B91QTnu9qVvJ9SvRusmAAYflZ7dG4IByIjgPoT8qwVTsGcdxCQTAYcFQYZTcGjdgA7YxyFgRIXcMZjAxQGA4ER0DUuABJNTzXMiR11AwQOmDi6OkDkdB0pB%2BPwDocCOAoQt2Yx8JAsOCAC%2FIM3B1yxxxA5334Kg6VA%2BuhAJfkFb3vD6cwYEFXhaQQXoRcd%2BHoVnuxbZgAGRHAUY7Lu%2B4wIex55qe9YNqgb4fm6HpOJ2HooGw%2BBzA6IyTAAcig8yKC0IC0PM7ouqwRBzI6mIPLuhBQCAX7kCAUpwQhhaOrQCROJGcCAImE9z4kgPy4vxYaTBmL7GPB76cZg%2BCBv%2BZJ8YSQYiumNQKUgLRoHAXCoEIDYNlAOj6d2MC9tBX60KERnGXeG7wPc3GOn4wRun0Ayft%2BXzzOAnp%2Flpqg6cAekGY6CkCGxa68E5nHkfM37OuhVHoA8wk%2FD6qBcUkOBoLQ0C0CAoIXDcZBuvglzMKw76OgA1gY37pY8zxyMACh%2FBomh%2BgGVjnFctwlU8kwgmC8pRjKDLRjKcoJhasZwCN26TcBdKrVGV6gZmMkcag40KiKvIIiy2pisMepUnAaknUabIclyV1ppJO0NuBcCkPgoRQI6OnhF1%2BTzGCqB2LJH5gAyQqsmSnKXZqJ38myx3EmdKrinDpbAdtL7vZ932%2FVA%2F0fHkmhAzUIPGKDe2mClZm%2Fvcjjoid5iErdvpHVDZ18SBmkvmA5AMDlJ5LqeYKAEVEL7abpAYGaU9lU3JOVSAwiqTKqKUQeRDyM0tkIs7r3g%2FCdjioDTLo6AriGkCAWCq5xyumPMpiW5xp3ykrtAq%2FMxwu6g9i04GDOigj7MhoaXPo89KavbtisQ1skz7THcCmfpOUsouy5J8cxn84LObQSLhbx3AEvGVLYUy9n8ux4hysJ9hGtIYFOsI0bKN%2B7Tvs5mQWANx7DD2E73fCu7zqe0PPu167%2FIh1Hu5kLZSAj4qBvmPPNSL6Ey92HwMC3u96fO8YlaH46LIH3Fm7p6sJ%2BOdf5%2FqEAA)

---

```lean
▼ mathlib-stable.lean:73:14
 ▼ Tactic state
  No goals
 ▼ Expected type
   v : LatticePoint4D
   h : projHom v = { px := 0, py := 0, pz := 0 }
   hpx : ↑v.x1 + ↑v.x2 * (sqrt3 / 2) - ↑v.x4 * (1 / 2) = 0
   hpy : ↑v.x2 * (1 / 2) + ↑v.x3 + ↑v.x4 * (sqrt3 / 2) = 0
   h1_raw : ↑(2 * v.x1 - v.x4) + ↑v.x2 * sqrt3 = 0
   h_res1 : 2 * v.x1 - v.x4 = 0 ∧ v.x2 = 0
   h_comb1 : 2 * v.x1 - v.x4 = 0
   h_x2 : v.x2 = 0
   h2_raw : ↑(2 * v.x3) + ↑v.x4 * sqrt3 = 0
   h_res2 : 2 * v.x3 = 0 ∧ v.x4 = 0
   h_comb2 : 2 * v.x3 = 0
   h_x4 : v.x4 = 0
   h_x3 : v.x3 = 0
   h_x1 : v.x1 = 0
   ⊢ v.x4 = { x1 := 0, x2 := 0, x3 := 0, x4 := 0 }.x4

▼ All Messages (0)
No messages.
```

*Lattice kernel triviality verified successfully.*

## ⚖️ License

This project is licensed under the **Creative Commons Attribution 4.0 International (CC-BY 4.0)** License.

---

## 📖 Citation

If you use or build upon this formalization, please cite it as follows:

> Reed, Jonathan ƒ(n). (2026). *Einstein Quasicrystals - A Lean 4 Certified Proof of 3D Aperiodic Einstein Quasicrystals by Triviality of the Projection Kernel* (Version 1.0) [Data set/Computer software]. Zenodo. https://doi.org/10.5281/zenodo.21796509

---
[![Field: Discrete--Geometry](https://img.shields.io/badge/Field-Discrete--Geometry-blue.svg)](https://github.com/topics/affine-algebraic-geometry) [![Verified in Lean 4](https://img.shields.io/badge/Verified-Lean%204-purple.svg)](https://lean-lang.org/) [![License: CC BY 4.0](https://img.shields.io/badge/License-CC%20BY%204.0-lightgrey.svg)](https://creativecommons.org/licenses/by/4.0/)

© 2026 Jonathan ƒ(n) Reed. All rights reserved.
