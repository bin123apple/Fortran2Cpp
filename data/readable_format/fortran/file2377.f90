! entropy_module.f90
MODULE entropy_module
  USE, INTRINSIC :: iso_fortran_env, ONLY: dp=>real64
  IMPLICIT NONE

CONTAINS

  SUBROUTINE entropy(f, temp, nx, ent)
    INTEGER, INTENT(IN) :: nx
    REAL(dp), INTENT(IN) :: f(nx), temp
    REAL(dp), INTENT(OUT) :: ent
    INTEGER :: i
    REAL(dp) :: fm
    REAL(dp), PARAMETER :: eps = 1.0d-10

    ent = 0.0_dp
    DO i = 1, nx
      fm = 0.5_dp * f(i)
      ent = ent + fm * LOG(eps + fm) + (1.0_dp - fm) * LOG(eps + 1.0_dp - fm)
    END DO
    ent = -2.0_dp * temp * ent
  END SUBROUTINE entropy

END MODULE entropy_module

! test_entropy.f90
PROGRAM test_entropy
  USE entropy_module
  IMPLICIT NONE
  INTEGER, PARAMETER :: nx = 5
  REAL(dp) :: temp, ent
  REAL(dp), DIMENSION(nx) :: f

  ! Initialize example data
  f = [0.1_dp, 0.2_dp, 0.3_dp, 0.4_dp, 0.5_dp]
  temp = 300.0_dp

  ! Call the entropy subroutine
  CALL entropy(f, temp, nx, ent)
  PRINT *, "Entropy: ", ent

END PROGRAM test_entropy