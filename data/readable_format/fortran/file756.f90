PROGRAM test_rotatd
    IMPLICIT NONE
    INTEGER, PARAMETER :: dp = KIND(1.0D0)
    INTEGER :: IP, JP, IA, IB, JA, JB, NI, NJ, LMW
    REAL(KIND=dp) :: CI(3), CJ(3)
    REAL(KIND=dp), ALLOCATABLE :: W(:)
    REAL(KIND=dp) :: ENUC

    ! Example initializations
    IP = 1; JP = 2; IA = 3; IB = 4; JA = 5; JB = 6; NI = 7; NJ = 8; LMW = 10
    CI = [1.0_dp, 2.0_dp, 3.0_dp]
    CJ = [4.0_dp, 5.0_dp, 6.0_dp]
    ALLOCATE(W(LMW))
    W = 0.0_dp  ! Example initialization

    CALL rotatd(IP, JP, IA, IB, JA, JB, NI, NJ, CI, CJ, W, LMW, ENUC)

    PRINT *, "ENUC:", ENUC

    CONTAINS

    SUBROUTINE rotatd(IP, JP, IA, IB, JA, JB, NI, NJ, CI, CJ, W, LMW, ENUC)
        INTEGER, INTENT(IN) :: IP, JP, IA, IB, JA, JB, NI, NJ, LMW
        REAL(KIND=dp), INTENT(IN) :: CI(3), CJ(3)
        REAL(KIND=dp), INTENT(INOUT) :: W(*)
        REAL(KIND=dp), INTENT(OUT) :: ENUC

        ! Example subroutine functionality: sum of elements in CI and CJ
        ENUC = SUM(CI) + SUM(CJ)
    END SUBROUTINE rotatd

END PROGRAM test_rotatd