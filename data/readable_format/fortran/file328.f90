PROGRAM main
    USE, INTRINSIC :: iso_fortran_env, ONLY: real64
    IMPLICIT NONE

    ! Declaration of variables for testing
    REAL(real64), DIMENSION(3, 25) :: COORD
    INTEGER :: I, J, IX, ISP
    INTEGER :: NI, NJ, IA, ID, JA, JD
    REAL(real64) :: RIJ, TOMB

    ! Initialization of variables for a simple test
    COORD = 0.0_real64
    I = 0; J = 0; IX = 0; ISP = 0
    NI = 1; NJ = 1; IA = 1; ID = 1; JA = 1; JD = 1
    RIJ = 0.0_real64; TOMB = 0.0_real64

    ! Calling the subroutine
    CALL delmol(COORD, I, J, NI, NJ, IA, ID, JA, JD, IX, RIJ, TOMB, ISP)

    ! Example print statement to verify results
    PRINT *, "COORD(1,1): ", COORD(1,1)
    PRINT *, "I: ", I
    PRINT *, "ISP: ", ISP
    ! Add more print statements as necessary to verify outcomes

CONTAINS

    SUBROUTINE delmol(COORD, I, J, NI, NJ, IA, ID, JA, JD, IX, RIJ, TOMB, ISP)
        USE, INTRINSIC :: iso_fortran_env, ONLY: real64
        REAL(real64), DIMENSION(3, 25), INTENT(INOUT) :: COORD
        INTEGER, INTENT(INOUT) :: I, J, IX, ISP
        INTEGER, INTENT(IN) :: NI, NJ, IA, ID, JA, JD
        REAL(real64), INTENT(INOUT) :: RIJ, TOMB

        ! The actual logic of delmol should be implemented here.
        ! For demonstration, let's just increment some variables.
        COORD(1,1) = COORD(1,1) + 1.0_real64
        I = I + 1
        ISP = ISP + 1

    END SUBROUTINE delmol

END PROGRAM main