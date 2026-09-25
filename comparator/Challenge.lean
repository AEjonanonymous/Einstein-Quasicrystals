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
  sorry

theorem projHom_injective_kernel (v : LatticePoint4D) (h : projHom v = { px := 0, py := 0, pz := 0 }) : v = ⟨0, 0, 0, 0⟩ := by
  sorry