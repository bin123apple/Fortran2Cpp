MODULE double_mod
  INTEGER, PARAMETER :: DP = KIND(1.0D0)
END MODULE double_mod

PROGRAM test_double
  USE double_mod
  IMPLICIT NONE
  REAL(KIND=DP) :: x
  x = 1.0_DP / 3.0_DP
  PRINT *, "Precision test for DP: ", (x == 1.0_DP / 3.0_DP)
END PROGRAM test_double