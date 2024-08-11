PROGRAM testZABS
  IMPLICIT NONE
  EXTERNAL ZABS
  DOUBLE PRECISION ZABS
  DOUBLE PRECISION ERROR
  DOUBLE PRECISION result
  ERROR = 0.D0

  ! Test 1
  result = ZABS(3.D0, 4.D0)
  IF (ABS(result - 5.D0) > 1.D-6) THEN
    ERROR = ERROR + 1
    PRINT *, 'Test 1 failed: Expected 5.0, got', result
  END IF

  ! Test 2
  result = ZABS(5.D0, 12.D0)
  IF (ABS(result - 13.D0) > 1.D-6) THEN
    ERROR = ERROR + 1
    PRINT *, 'Test 2 failed: Expected 13.0, got', result
  END IF

  ! Test 3
  result = ZABS(0.D0, 0.D0)
  IF (ABS(result) > 1.D-6) THEN
    ERROR = ERROR + 1
    PRINT *, 'Test 3 failed: Expected 0.0, got', result
  END IF

  IF (ERROR == 0) THEN
    PRINT *, 'All tests passed successfully.'
  ELSE
    PRINT *, 'Number of tests failed:', ERROR
  END IF

END PROGRAM testZABS

DOUBLE PRECISION FUNCTION ZABS (ZR, ZI)
  DOUBLE PRECISION ZR, ZI, U, V, Q, S
  U = ABS(ZR)
  V = ABS(ZI)
  S = U + V
  S = S*1.0D+0
  IF (S.EQ.0.0D+0) THEN
    ZABS = 0.0D+0
    RETURN
  END IF
  IF (U.GT.V) THEN
    Q = U/V
    ZABS = V*SQRT(1.D+0+Q*Q)
    RETURN
  ELSE
    Q = V/U
    ZABS = U*SQRT(1.D+0+Q*Q)
    RETURN
  END IF
END FUNCTION ZABS