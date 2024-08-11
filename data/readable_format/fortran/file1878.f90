MODULE HypotModule
    USE, INTRINSIC :: IEEE_ARITHMETIC
    IMPLICIT NONE
CONTAINS
    REAL(KIND=8) FUNCTION HYPOT(X, Y)
        REAL(KIND=8), INTENT(IN) :: X, Y
        REAL(KIND=8) :: SCALED_X, SCALED_Y, SCALED_RESULT
        INTEGER :: EXP_X, EXP_Y
        EXP_X = EXPONENT(X)
        EXP_Y = EXPONENT(Y)
        IF (X == 0.0_8 .OR. Y == 0.0_8) THEN
            HYPOT = ABS(X) + ABS(Y)
        ELSE IF (2*ABS(EXP_X - EXP_Y) > DIGITS(X) + 1) THEN
            HYPOT = MAX(ABS(X), ABS(Y))
        ELSE
            SCALED_X = SCALE(X, -EXP_X)
            SCALED_Y = SCALE(Y, -EXP_X)
            SCALED_RESULT = SQRT(SCALED_X**2 + SCALED_Y**2)
            HYPOT = SCALE(SCALED_RESULT, EXP_X)
        END IF
    END FUNCTION HYPOT
END MODULE HypotModule

PROGRAM TEST_HYPOT
    USE HypotModule
    IMPLICIT NONE
    REAL(KIND=8) :: result

    ! Normal case
    result = HYPOT(3.0_8, 4.0_8)
    PRINT *, "HYPOT(3, 4) = ", result

    ! Test near overflow
    result = HYPOT(1.0E+150_8, 1.0E+150_8)
    PRINT *, "HYPOT(1.0E+150, 1.0E+150) = ", result

    ! Test for underflow
    result = HYPOT(1.0E-200_8, 1.0E-200_8)
    PRINT *, "HYPOT(1.0E-200, 1.0E-200) = ", result

    ! Test with large and small values
    result = HYPOT(1.0E+150_8, 1.0E-150_8)
    PRINT *, "HYPOT(1.0E+150, 1.0E-150) = ", result
END PROGRAM TEST_HYPOT