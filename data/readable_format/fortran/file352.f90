MODULE SINDD_MOD
  IMPLICIT NONE
CONTAINS
  FUNCTION SINDD(ALFA)
    IMPLICIT NONE
    REAL(8) :: SINDD
    REAL(8), INTENT(IN) :: ALFA
    REAL(8) :: ALFARAD
    REAL(8), PARAMETER :: PI=3.14159265358979323840D0
    
    ALFARAD = ALFA * PI / 180D0
    SINDD = SIN(ALFARAD)
  END FUNCTION SINDD
END MODULE SINDD_MOD

PROGRAM testSINDD
  USE SINDD_MOD
  IMPLICIT NONE
  REAL(8) :: result
  
  ! Test the SINDD function with a known value
  result = SINDD(30.0D0)
  PRINT *, 'Sine of 30 degrees: ', result
  PRINT *, 'Expected value: ', 0.5D0
  
  IF (ABS(result - 0.5D0) < 1E-6) THEN
     PRINT *, 'Test passed.'
  ELSE
     PRINT *, 'Test failed.'
  END IF
END PROGRAM testSINDD