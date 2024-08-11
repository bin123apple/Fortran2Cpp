! Define the LTNEW subroutine
SUBROUTINE LTNEW(MDIM, LINK)
    INTEGER, INTENT(IN) :: MDIM
    INTEGER, INTENT(OUT) :: LINK(2, MDIM)
    INTEGER :: I

    DO I = 1, MDIM
        LINK(1, I) = 0
    END DO
END SUBROUTINE LTNEW

! Main program to test LTNEW subroutine
PROGRAM TEST_LTNEW
    IMPLICIT NONE
    INTEGER, PARAMETER :: MDIM = 10
    INTEGER :: LINK(2, MDIM)
    INTEGER :: I

    ! Call the LTNEW subroutine
    CALL LTNEW(MDIM, LINK)

    ! Print the results to verify
    DO I = 1, MDIM
        PRINT *, 'LINK(1,', I, ') = ', LINK(1, I)
    END DO

END PROGRAM TEST_LTNEW