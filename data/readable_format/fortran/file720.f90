PROGRAM test_INHG_FROM_PA
  IMPLICIT NONE
  REAL :: result
  REAL, PARAMETER :: BADDATA = -999.0
  REAL, PARAMETER :: PA1 = 101325.0  ! Standard atmospheric pressure in Pascals
  REAL, PARAMETER :: INHG1 = 29.9213 ! Standard atmospheric pressure in inHg

  ! Test 1: Standard atmospheric pressure
  result = INHG_FROM_PA(PA1, BADDATA)
  IF (ABS(result - INHG1) > 0.0001) THEN
     PRINT *, 'Test 1 failed: Expected', INHG1, 'but got', result
  ELSE
     PRINT *, 'Test 1 passed.'
  END IF

  ! Test 2: Bad data
  result = INHG_FROM_PA(BADDATA, BADDATA)
  IF (result /= BADDATA) THEN
     PRINT *, 'Test 2 failed: Expected', BADDATA, 'but got', result
  ELSE
     PRINT *, 'Test 2 passed.'
  END IF

CONTAINS

  REAL FUNCTION INHG_FROM_PA(PA, BADDATA)
    IMPLICIT NONE
    REAL, INTENT(IN) :: PA, BADDATA
    
    IF (PA .NE. BADDATA) THEN
       INHG_FROM_PA = PA / 3386.39
    ELSE
       INHG_FROM_PA = BADDATA
    END IF
  END FUNCTION INHG_FROM_PA

END PROGRAM test_INHG_FROM_PA