! Define the DLAPY3 function
DOUBLE PRECISION FUNCTION DLAPY3(X, Y, Z)
  DOUBLE PRECISION   X, Y, Z
  DOUBLE PRECISION   ZERO
  PARAMETER          (ZERO = 0.0D0)
  DOUBLE PRECISION   W, XABS, YABS, ZABS
  INTRINSIC          ABS, MAX, SQRT

  XABS = ABS(X)
  YABS = ABS(Y)
  ZABS = ABS(Z)
  W = MAX(XABS, YABS, ZABS)
  IF(W.EQ.ZERO) THEN
     DLAPY3 =  XABS + YABS + ZABS
  ELSE
     DLAPY3 = W*SQRT((XABS/W)**2+(YABS/W)**2+(ZABS/W)**2)
  END IF
  RETURN
END

! Begin the test program
PROGRAM test_dlapy3
  DOUBLE PRECISION DLAPY3
  DOUBLE PRECISION result
  
  ! Test 1
  result = DLAPY3(3.0D0, 4.0D0, 0.0D0)
  PRINT *, 'Test 1 (3,4,0): Should be close to 5.0 - Result:', result
  
  ! Test 2
  result = DLAPY3(0.0D0, 0.0D0, 0.0D0)
  PRINT *, 'Test 2 (0,0,0): Should be 0.0 - Result:', result
  
  ! Test 3
  result = DLAPY3(1.0D0, 1.0D0, 1.0D0)
  PRINT *, 'Test 3 (1,1,1): Should be close to 1.732 - Result:', result
  
  ! Feel free to add more tests as needed
  
END PROGRAM test_dlapy3