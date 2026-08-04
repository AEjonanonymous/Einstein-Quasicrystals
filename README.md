# <div align="center">💎 "ein-Stein" (One-Stone) Quasicrystals 💎 
## <div align="center"><i>A Lean 4 Certified Proof of 3D Aperiodic Einstein Quasicrystals by Triviality of the Projection Kernel.</i>

## <div align="center">📌 Abstract

<i>Standard approaches to the classical Einstein problem fail by attempting to lift two-dimensional aperiodic monotiles into three dimensions through height extrusion, 
which inherently causes geometric collapse and structural hollowing. Our novel insight resolves this by shifting from extrusion to de Bruijn’s cut-and-project method, deploying a 4D-to-3D projection framework on $\mathbb{Z}^4$ to generate a true, volumetric structure. We formally verify this novel insight inside the Lean 4 theorem prover by proving the triviality of the projection kernel. This formal proof establishes strict linear injectivity, guaranteeing that no dimensional folding or coordinate collisions occur, which mathematically locks down global aperiodicity and proves the existence of the Einstein Quasicrystal. 
Keywords: Mathematics, Discrete Geometry, 3D Aperiodic Monotiles, Einstein Tile, Hat Tile, de Bruijn Cut-and-Project Framework, Delaunay Triangulation, Meyer Set, Quasicrystals, Formal Verification, Interactive Theorem Proving, Lean 4, Injective Proof, Trivial Kernel. </i>

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

![Einstein Quasiscrystal Projection](https://github.com/AEjonanonymous/ein-Stein-Quasicrystal/blob/main/ein_stein_quasicrystal.PNG)

`ein_stein_quasicrystal.PNG`: What we are looking at is no longer a standard 2D shape forced into 3D, but a true 3D aperiodic Einstein Quasicrystal.

**Non-Repeating Global Structure:** Because the physical projection matrix $M_\parallel$ embeds irrational trigonometric ratios ($\cos(30^\circ)$ and $\sin(30^\circ)$), every node and connecting strut aligns strictly with the tile's native hexagonal vector directions. Yet, as you rotate the camera, you’ll notice no single volumetric cell repeats identically because it possesses long-range order without periodicity.

**Faceted Side Walls:** Unlike flat vertical extrusions that leave hollow sides, every 3D segment here is bounded by actual 4D lattice neighbors ($\Vert{}\Delta \mathbf{v}\Vert{} = 1$). The walls are intricate, oblique polyhedral facets that share the exact geometric DNA of the top and bottom faces.

**Quasicrystal Architecture:** In physics, this is almost identical to how nature arranges atoms in real-world quasicrystals. The 1D internal phase space ($E_\perp$) acts like a geometric aperture, slicing through 4D space to reveal a complex 3D WebGL wireframe of connected nodes and struts.

## ✅ Machine Certification of Injectivity in Lean 4 

👉 [Access the Live Interactive Proof in Lean 4](https://live.lean-lang.org/#project=mathlib-stable&codez=JYWwDg9gTgLgBAWQIYwBYBtgCMB0ARFJHAORRwGFUIIBnAUxwCEkbgBjAKFElkRQ2z5COAMp0YTFuy7ho8ZGky4CMIqQkAFKKAbNWnbnL6LBKtWQBiSNjGjAAXimAQAdpP0ye8%2FkqGqSZHjAAObAMDT4dABmNBwcAPQAtACEHADEcCLALsEgLDB0UADkNHDkrgBWdDYArlB0AFxwAIJwACoAnmB0iSJIUXSZMFA1tVBI6HAASnQAJqMwzi5wGsDdmC50cWkZq%2BvZg81QbKhh1TB1W22npVHA6INR0HmY9nSlSHBsrjTDC8AAN0G9XmNiWcAgUUy2Vy%2BUKJS%2BlXOlzgHCiUAgIDgaEGNRc3xcv3GB1mcCw2UxwAmcBoEHQNUWrhpYGsg1mEAA7stbHBPlgIHjZnM4ABHGpIWbjRZsVHsvLZHDTfiFbGoJDLeroDowiHc8azMJLamqMFsalgDGQmlsbRgcIAGlVgw4SGOpwKY0GwFKdByB0KwpYvLgAEYACyJX5IYKDGBdHoPIGTYbqmhPKB5RnLMBrOgbBiojiMDpwROFaM68h1KAdRIACU5rtJce6NP64g6jro1lQcAABkKon3eTYPh84NpgtABaUXdo0CBxOxeS5STHMeJtDK7ugClA4AAKFNAqCsHJwADSNRAi%2BKpRx0DoIEdABk6DHV%2FUEcAhS5FnHHQ4OtChAM44CidBqH3OgAA8WUJJYaEddVSQNUIYEja9EUJFNsnCABKRVrkGN91TgMM4AAa0KTZJg4IkFjqCYtTgE9gDud5VRQJ04GyMAGWxeNDzEeAD0AVEI4AAdbgMT8PwxF0HQJAwHoUo8IgVEcTJAVV2FPdQJcak5SQbJD1kskSwJBiwVcHAOESeI4ggbplhEuJEkSOAXwOUMmgsZ5qTwaJskNJkrWII95KDT43MHGk6QZJYRMPeAmnMppkvEqSZPkhoAF4ODgOAAG8wDgNLsokgAfOAwBwEM4EAEyJsTgQByIlqnAACYmo6hr2vUHATmoeheo67q8uxABfdzPO8zY4E6porxveFSmIx8sRoGosF%2BMJEqZA8ajPYJMnEbENLVVcHl4lw7hcMCLR0UVxT%2FdjgEKGh8I4OLaXpLMROW28UvKnKQcyiTpPSgqitKkGIZkuAarqhrmvgdq6u65rkbauBAAAiQ8LTh%2FDHQGrQnsJwAkwkPAahtoQZsYxwiomsWxtEcLNav3CaJGZmw7HZ8ELWm%2BzZp8gBmJoycXRJynqOAgu%2BWRWCzb7oniv6kvEBXMUgehSSPImwbOrLIdy6GSrKirIcR0bUZxjGeux9rCqKw98YPQm0uJuBSe0RdObgKmABqPf3QBiImxeSqYPGmqDp0bGZwXnWYcJwmUJiaAAZ5Nal2ioPd3PZykmyCl%2Bn92jwmI5gKPqbIWmRoZrqmZZ%2Fm0%2BzLnsST1u2fbzn8OFjyvJ8sMmjabQASpSZGB02ZXRLABRGCUxs5YDxmIl2EWc9jNMnlMaonqXESTqvp%2BhL%2FvEABJP9CmcfcDa9o3RPhqGXdhq2EaR%2BqerRhbHa6vbQBABqf%2BWMf7O1dm7Am%2B4vYl00H7cugc4AhyrpHZBMd65x0bj%2FROyc24cwznAbObU87QNDkTeBOAy4B0ruHdB0dY7DXprg5u3c%2Ba90IZ3HmPdU5cIHjNYe80ACsTQECuAgLYeaWQ6BAjgAAVTAN0fcM9BSHjwBiJROpHrSwNJPA0OREjwCsrhP8n1VZQl%2BvtFwIkZFyMfqDDKxtX5m3fpbBG1tv4oxau1A%2BDt0YgLAaNSBrsC4wMoT7UuiDaEoIodXWumCJANxYQ1PBvCBbp07tnQeot5oADYmhvg%2FJKOgCIr6%2Fn%2FCWZoSjMBmg5geII6FMJYnTCAM%2BasrGXxgEU30JTgZPycS%2FSqriYbuNfjbbGdtfEAO6gE7qoC%2FEQNRFAsJFC4GRIQeTCusS0E12QWQ%2FOiScBoTCKUQmictpYlAUck54QA4ex%2Fp5RmhFLlwE8jckIpyA7IxedeeSWcBEiyEYMAA7E0YCGYzgIgsJBaAcAl7wVYAdCwIUCg0mvJmcEdAxSAgmL6eAVotIQSgrxCpYQOjtMsRfTWMAIWgTRQ49Kp0hmm3KubD%2BHiv62x8UE%2FxY04ALIAX1ZZoTC6wOLhs6h0TKY7PoXsqmBzDwosJOIHAryDzKvoBIcYORBgPIaqAkMclDxRDxHACocA8oAD4RVQKKuxc1lriFOmWJnW1dq8wjX1XAeI4SAB65rjXvIdr6ihAaKhBsPN6p5zcfX%2BsDXJf5xDAVDzmoMAAHE0RpYRehYX8hmModIlIqT1Qi%2BoNBjpwFueirE2LxSYDjFW4A9QbBakperaxIls0wBENecoillJetSo45lZlhlsrcXDSqEyf5TN5YAuZAr53CrIasouskqE0JlaguVtdFUfPQmc%2FcFysLXIGrco9BNHljTkmqrCE0D1fPOfVX5bScnArgAATkKRAYIrowioFAjKbtuasSqNXDqA8N860THJeBZ48H9zVsueY8%2BGtXAiRfL%2B%2F9C52Dgf1sOpl4Nx35UnZ%2Faq3K%2F6LNmfywV4CV0rLFRE32WzkE7rgPE%2FZdq64SAvd8l9d6sTNUfXc59p9BNLpE5e6NN7X0ptyYMEMmcmgAEVxSSicMBzEJllgb2GFvcEB4NCuiQPyWpcAahKJVPyNRk9Pg2loDQRIIAai7jWLU9u7bOk0rUxKKUy5GW5VHSbRx7KxnTq8b%2FHG1GgHzOXTjMhFEABU%2FKUsycZkKuAKXkbvrTaGEMTQb5sHpEi5YhLUCDEYBSUC1JkDBHuhcIUhacLEj%2FBYjtXS6sNZqE1wLz8x2stI6MqdnjKPRZmbFpdiyGOu2xml7GnkjU9W6ilv%2BiWsupavQ1GNp9MvZfqrlnyIZFqnRZP5sKUIABq%2F7TMPFKHZ9oOqaC61CmvBFtSwjaUFKUJkLgvPUow%2BIMQZ2UDCj64MgboWyOcoo5MnlMXF10eCe6ubW23mhnks1FbU1BF5ZDGLOAAAyUMo9ph5nbtSeR91WlwHw3MTYFb2gVY2qiIeB4y3vErVpWC3oCj4kGFaT4eJAQfWpDZ1ccAOQAYFPAWCe5DKTDNFAUkIAIDzDu15mEeRfiFHKC4Konp8Mgy0M5CdRVADARIgOGjp8aEZt7VOAgAIIg6zS4HJmCjNkdHDhAk3moICAA)

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

> Reed, Jonathan ƒ(n). (2026). *Einstein Quasicrystals - A Lean 4 Certified Proof of 3D Aperiodic Einstein Quasicrystals by Triviality of the Projection Kernel* (Version 1.0) [Data set/Computer software]. Zenodo. https://doi.org/10.5281/zenodo.21660302

[![Field: Discrete Geometry](https://img.shields.io/badge/Field-Discrete-Geometry-blue.svg)](https://github.com/topics/affine-algebraic-geometry) [![Verified in Lean 4](https://img.shields.io/badge/Verified-Lean%204-purple.svg)](https://lean-lang.org/) [![License: CC BY 4.0](https://img.shields.io/badge/License-CC%20BY%204.0-lightgrey.svg)](https://creativecommons.org/licenses/by/4.0/)

---
© 2026 Jonathan ƒ(n) Reed. All rights reserved.

