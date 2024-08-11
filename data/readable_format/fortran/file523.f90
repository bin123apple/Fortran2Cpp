! powell_mod.f90
MODULE powell_mod
  IMPLICIT NONE
  INTEGER, PARAMETER :: dp_kind = KIND(1.0D0)
CONTAINS
  SUBROUTINE trsapp(n, d, crvmin)
    INTEGER, INTENT(IN) :: n
    REAL(KIND=dp_kind), INTENT(IN) :: d(n)
    REAL(KIND=dp_kind), INTENT(OUT) :: crvmin
    INTEGER :: i
    crvmin = 0.0_dp_kind
    DO i = 1, n
       crvmin = crvmin + d(i)**2
    END DO
  END SUBROUTINE trsapp
END MODULE powell_mod

! test_powell.f90
PROGRAM test_trsapp
  USE powell_mod, ONLY: dp_kind, trsapp
  IMPLICIT NONE
  INTEGER, PARAMETER :: n = 2
  REAL(KIND=dp_kind) :: d(n) = [1.0_dp_kind, 2.0_dp_kind], crvmin

  CALL trsapp(n, d, crvmin)

  PRINT *, "Step: Not applicable in this test"
  PRINT *, "CRVMIN: ", crvmin
END PROGRAM test_trsapp