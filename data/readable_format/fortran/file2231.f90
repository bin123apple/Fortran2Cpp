PROGRAM TestIauPas
    IMPLICIT NONE
    DOUBLE PRECISION AL, AP, BL, BP, THETA

    ! Example values for testing
    AL = 0.0D0
    AP = 0.0D0
    BL = 1.0D0
    BP = 1.0D0

    CALL iau_PAS(AL, AP, BL, BP, THETA)

    PRINT *, "THETA =", THETA

CONTAINS

    SUBROUTINE iau_PAS(AL, AP, BL, BP, THETA)
        IMPLICIT NONE
        DOUBLE PRECISION, INTENT(IN) :: AL, AP, BL, BP
        DOUBLE PRECISION, INTENT(OUT) :: THETA
        DOUBLE PRECISION :: DL, X, Y

        DL = BL - AL
        Y = SIN(DL) * COS(BP)
        X = SIN(BP) * COS(AP) - COS(BP) * SIN(AP) * COS(DL)

        IF (X /= 0D0 .OR. Y /= 0D0) THEN
            THETA = ATAN2(Y, X)
        ELSE
            THETA = 0D0
        END IF
    END SUBROUTINE iau_PAS

END PROGRAM TestIauPas