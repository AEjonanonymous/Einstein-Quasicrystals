import Mathlib

noncomputable section

@[ext]
structure LatticePoint4D where
  x1 : ℤ
  x2 : ℤ
  x3 : ℤ
  x4 : ℤ
  deriving DecidableEq

@[ext]
structure Point3D where
  px : ℝ
  py : ℝ
  pz : ℝ
  deriving DecidableEq

def sqrt3 : ℝ := Real.sqrt 3
def sqrt2 : ℝ := Real.sqrt 2

def projHom (v : LatticePoint4D) : Point3D := 
  { px := (v.x1 : ℝ) + (v.x2 : ℝ) * (sqrt3 / 2) - (v.x4 : ℝ) * (1 / 2)
  , py := (v.x2 : ℝ) * (1 / 2) + (v.x3 : ℝ) + (v.x4 : ℝ) * (sqrt3 / 2)
  , pz := (v.x1 : ℝ) * (sqrt3 / 3) + (v.x3 : ℝ) * (sqrt3 / 3) - (v.x4 : ℝ) * (sqrt2 / 2) }

lemma sqrt3_rat_irr (a b : ℤ) (h : (a : ℝ) + (b : ℝ) * sqrt3 = 0) : a = 0 ∧ b = 0 := by
  by_cases hb : b = 0
  · subst hb
    simp only [Int.cast_zero, zero_mul, add_zero] at h
    exact ⟨by exact_mod_cast h, rfl⟩
  · exfalso
    have hb_ne : (b : ℝ) ≠ 0 := by exact_mod_cast hb
    have h_irr : Irrational sqrt3 := Nat.Prime.irrational_sqrt (by norm_num)
    have h_eq : sqrt3 = ↑(-a) / ↑b := by
      have h_lin : (b : ℝ) * sqrt3 = - (a : ℝ) := by linarith [h]
      rw [Int.cast_neg]
      exact (eq_div_iff hb_ne).mpr (by linarith [h_lin])
    exact h_irr.ne_rational (-a) b h_eq

theorem projHom_injective_kernel (v : LatticePoint4D) (h : projHom v = { px := 0, py := 0, pz := 0 }) : v = ⟨0, 0, 0, 0⟩ := by
  have hpx : (v.x1 : ℝ) + (v.x2 : ℝ) * (sqrt3 / 2) - (v.x4 : ℝ) * (1 / 2) = 0 := by
    exact congr_arg Point3D.px h
  have hpy : (v.x2 : ℝ) * (1 / 2) + (v.x3 : ℝ) + (v.x4 : ℝ) * (sqrt3 / 2) = 0 := by
    exact congr_arg Point3D.py h
  
  have h1_raw : ((2 * v.x1 - v.x4 : ℤ) : ℝ) + (v.x2 : ℝ) * sqrt3 = 0 := by
    push_cast at hpx ⊢
    linarith [hpx]
  
  have h_res1 := sqrt3_rat_irr (2 * v.x1 - v.x4) v.x2 h1_raw
  have h_comb1 := h_res1.1
  have h_x2 := h_res1.2

  have h2_raw : ((2 * v.x3 : ℤ) : ℝ) + (v.x4 : ℝ) * sqrt3 = 0 := by
    have hpy2 := hpy
    rw [h_x2] at hpy2
    push_cast at hpy2 ⊢
    linarith [hpy2]
  
  have h_res2 := sqrt3_rat_irr (2 * v.x3) v.x4 h2_raw
  have h_comb2 := h_res2.1
  have h_x4 := h_res2.2

  have h_x3 : v.x3 = 0 := by omega
  have h_x1 : v.x1 = 0 := by omega

  ext
  · exact h_x1
  · exact h_x2
  · exact h_x3
  · exact h_x4