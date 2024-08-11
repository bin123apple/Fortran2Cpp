PROGRAM testDLAPY3
    IMPLICIT NONE
    DOUBLE PRECISION :: result

    ! Test case 1
    result = DLAPY3(1.0D0, 2.0D0, 2.0D0)
    PRINT *, 'Test 1 (1, 2, 2): Expected ~3, Got ', result

    ! Test case 2
    result = DLAPY3(0.0D0, 3.0D0, 4.0D0)
    PRINT *, 'Test 2 (0, 3, 4): Expected ~5, Got ', result

    ! Test case 3
    result = DLAPY3(0.0D0, 0.0D0, 0.0D0)
    PRINT *, 'Test 3 (0, 0, 0): Expected 0, Got ', result

CONTAINS

    DOUBLE PRECISION FUNCTION DLAPY3(X, Y, Z)
        DOUBLE PRECISION, INTENT(IN) :: X, Y, Z
        DOUBLE PRECISION :: W, XABS, YABS, ZABS

        XABS = ABS(X)
        YABS = ABS(Y)
        ZABS = ABS(Z)
        W = MAX(XABS, YABS, ZABS)

        IF (W == 0.0D0) THEN
            DLAPY3 = XABS + YABS + ZABS
        ELSE
            DLAPY3 = W * SQRT((XABS / W)**2 + (YABS / W)**2 + (ZABS / W)**2)
        END IF
    END FUNCTION DLAPY3

END PROGRAM testDLAPY3