PROGRAM test_slapy3
  IMPLICIT NONE

  REAL :: result
  
  ! Test 1: All zeros
  result = SLAPY3(0.0, 0.0, 0.0)
  PRINT *, "Test 1 (All zeros): ", result
  
  ! Test 2: Positive numbers
  result = SLAPY3(3.0, 4.0, 5.0)
  PRINT *, "Test 2 (Positive numbers): ", result
  
  ! Test 3: Negative numbers
  result = SLAPY3(-3.0, -4.0, -5.0)
  PRINT *, "Test 3 (Negative numbers): ", result
  
  ! Test 4: Mix of positive and negative
  result = SLAPY3(-3.0, 4.0, -5.0)
  PRINT *, "Test 4 (Mix of positive and negative): ", result

  CONTAINS
  
  REAL FUNCTION SLAPY3(X, Y, Z)
    IMPLICIT NONE
    REAL, INTENT(IN) :: X, Y, Z
    REAL :: W, XABS, YABS, ZABS
    REAL, PARAMETER :: ZERO = 0.0E0
    INTRINSIC ABS, MAX, SQRT
    
    XABS = ABS(X)
    YABS = ABS(Y)
    ZABS = ABS(Z)
    W = MAX(XABS, MAX(YABS, ZABS))
    IF (W.EQ.ZERO) THEN
       SLAPY3 = XABS + YABS + ZABS
    ELSE
       SLAPY3 = W * SQRT((XABS / W)**2 + (YABS / W)**2 + (ZABS / W)**2)
    END IF
  END FUNCTION SLAPY3

END PROGRAM test_slapy3