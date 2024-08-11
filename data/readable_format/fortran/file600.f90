PROGRAM TestDLAPY3
  IMPLICIT NONE
  DOUBLE PRECISION :: error

  error = 1.0D-10

  ! Test 1
  CALL performTest(1.0D0, 2.0D0, 2.0D0, 3.0D0, error)

  ! Test 2
  CALL performTest(0.0D0, 0.0D0, 0.0D0, 0.0D0, error)

  ! Test 3
  CALL performTest(-3.0D0, 4.0D0, 0.0D0, 5.0D0, error)

CONTAINS

  DOUBLE PRECISION FUNCTION DLAPY3(X, Y, Z)
    DOUBLE PRECISION, INTENT(IN) :: X, Y, Z
    DOUBLE PRECISION :: W, XABS, YABS, ZABS
    DOUBLE PRECISION, PARAMETER :: ZERO = 0.0D0

    XABS = ABS(X)
    YABS = ABS(Y)
    ZABS = ABS(Z)
    W = MAX(XABS, YABS, ZABS)

    IF (W.EQ.ZERO) THEN
      DLAPY3 = ZERO
    ELSE
      DLAPY3 = W * SQRT((XABS / W)**2 + (YABS / W)**2 + (ZABS / W)**2)
    END IF
  END FUNCTION DLAPY3

  SUBROUTINE performTest(X, Y, Z, expected, error)
    DOUBLE PRECISION, INTENT(IN) :: X, Y, Z, expected, error
    DOUBLE PRECISION :: result

    result = DLAPY3(X, Y, Z)
    IF (ABS(result - expected) > error) THEN
       PRINT *, 'Test Failed: Expected', expected, 'Got', result
    ELSE
       PRINT *, 'Test Passed'
    END IF
  END SUBROUTINE performTest

END PROGRAM TestDLAPY3