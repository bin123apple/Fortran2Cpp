PROGRAM TestRSCO
    IMPLICIT NONE
    INTEGER, PARAMETER :: LENRLS = 218
    INTEGER, PARAMETER :: LENILS = 33
    REAL :: RSAV(LENRLS)
    INTEGER :: ISAV(LENILS)
    REAL :: RLS(218)
    INTEGER :: ILS(33)
    COMMON /DEBDF1/ RLS, ILS
    INTEGER :: I

    ! Initialize test data
    DO I = 1, LENRLS
        RSAV(I) = I * 1.0
    END DO

    DO I = 1, LENILS
        ISAV(I) = I
    END DO

    ! Call the subroutine
    CALL RSCO(RSAV, ISAV)

    ! Verify the results
    PRINT *, 'Testing RLS array:'
    DO I = 1, LENRLS
        IF (RLS(I) /= RSAV(I)) THEN
            PRINT *, 'Test failed at RLS(', I, ')'
            STOP
        END IF
    END DO
    PRINT *, 'RLS array test passed.'

    PRINT *, 'Testing ILS array:'
    DO I = 1, LENILS
        IF (ILS(I) /= ISAV(I)) THEN
            PRINT *, 'Test failed at ILS(', I, ')'
            STOP
        END IF
    END DO
    PRINT *, 'ILS array test passed.'

END PROGRAM TestRSCO

SUBROUTINE RSCO (RSAV, ISAV)
    INTEGER :: ISAV(*), I, ILS(33), LENILS, LENRLS
    REAL :: RSAV(*), RLS(218)
    COMMON /DEBDF1/ RLS, ILS
    SAVE LENRLS, LENILS
    DATA LENRLS /218/, LENILS /33/

    DO I = 1, LENRLS
        RLS(I) = RSAV(I)
    END DO

    DO I = 1, LENILS
        ILS(I) = ISAV(I)
    END DO

END SUBROUTINE RSCO