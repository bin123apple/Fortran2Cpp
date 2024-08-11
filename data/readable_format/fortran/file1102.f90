! combined_rsc.f90
MODULE rsc_module
  USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
  IMPLICIT NONE

  CONTAINS

  REAL(KIND=REAL64) FUNCTION rsc(K, NA, EA, NB, EB, NC, EC, ND, ED)
    INTEGER, INTENT(IN) :: K, NA, NB, NC, ND
    REAL(KIND=REAL64), INTENT(IN) :: EA, EB, EC, ED
    rsc = (EA + EB + EC + ED) / 4.0_REAL64 * (K + NA + NB + NC + ND)
  END FUNCTION rsc

END MODULE rsc_module

PROGRAM test_rsc
  USE rsc_module
  IMPLICIT NONE
  REAL(KIND=REAL64) :: result
  
  ! Test the rsc function with example values
  result = rsc(1, 2, 3.0_REAL64, 3, 4.0_REAL64, 4, 5.0_REAL64, 5, 6.0_REAL64)
  
  ! Output the result
  PRINT *, "Result of rsc function: ", result
  ! Optionally, compare with expected value and print if it matches expectations
END PROGRAM test_rsc