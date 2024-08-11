PROGRAM test_coe
    IMPLICIT NONE
    DOUBLE PRECISION, DIMENSION(75) :: C
    DOUBLE PRECISION :: X2, Y2, Z2, R
    INTEGER :: NORBI, NORBJ, i

    ! Test values
    X2 = 1.0D0
    Y2 = 2.0D0
    Z2 = 3.0D0
    NORBI = 4
    NORBJ = 5

    CALL coe(X2, Y2, Z2, NORBI, NORBJ, C, R)

    ! Check the results
    IF (R /= 6.0D0) THEN
        PRINT *, "Test failed for R calculation."
    ELSE
        PRINT *, "R calculation passed."
    END IF

    DO i = 1, 75, 2
        IF (C(i) /= 4.0D0 .OR. (i+1 <= 75 .AND. C(i+1) /= 5.0D0)) THEN
            PRINT *, "Test failed for C array filling at index:", i
            EXIT
        END IF
    END DO

    PRINT *, "All tests passed for C array filling."

CONTAINS

    SUBROUTINE coe(X2, Y2, Z2, NORBI, NORBJ, C, R) 
        IMPLICIT NONE
        DOUBLE PRECISION, INTENT(IN) :: X2, Y2, Z2
        INTEGER, INTENT(IN) :: NORBI, NORBJ
        DOUBLE PRECISION, DIMENSION(75), INTENT(OUT) :: C
        DOUBLE PRECISION, INTENT(OUT) :: R
        INTEGER :: i

        ! Example functionality for the subroutine
        R = X2 + Y2 + Z2
        DO i = 1, 75, 2
            C(i) = NORBI
            IF (i + 1 <= 75) THEN
                C(i + 1) = NORBJ
            END IF
        END DO
    END SUBROUTINE coe

END PROGRAM test_coe