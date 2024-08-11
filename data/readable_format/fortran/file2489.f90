PROGRAM TEST_H12
    IMPLICIT NONE
    INTEGER :: MDE, LPIVOT, L1, M, IUE, ICE, ICV, NCV
    DOUBLE PRECISION :: UP
    DOUBLE PRECISION, DIMENSION(:,:), ALLOCATABLE :: U
    DOUBLE PRECISION, DIMENSION(:), ALLOCATABLE :: C

    MDE = 1
    LPIVOT = 1
    L1 = 2
    M = 3
    IUE = 1
    ICE = 1
    ICV = 1
    NCV = 1

    ALLOCATE(U(1, M+1)) ! Adjusted for 1-based index
    ALLOCATE(C(M+1))    ! Adjusted for 1-based index

    U(1, 1) = 0.0
    U(1, 2) = 1.0
    U(1, 3) = 2.0
    U(1, 4) = 3.0       ! Added for matching the array size
    UP = 0.0

    C(1) = 0.0
    C(2) = 1.0
    C(3) = 2.0
    C(4) = 3.0          ! Added for matching the array size

    CALL H12(MDE, LPIVOT, L1, M, U, IUE, UP, C, ICE, ICV, NCV)

    PRINT *, "UP: ", UP
    PRINT *, "C: ", C

END PROGRAM TEST_H12

SUBROUTINE H12 (MDE, LPIVOT, L1, M, U, IUE, UP, C, ICE, ICV, NCV)
    INTEGER, INTENT(IN) :: MDE, LPIVOT, L1, M, IUE, ICE, ICV, NCV
    DOUBLE PRECISION, INTENT(INOUT) :: U(IUE, M+1), C(*), UP
    DOUBLE PRECISION :: SM, B, CL, ONE, CLINV, SM1
    INTEGER :: I2, INCR, J, I, I3, I4
    ONE = 1.0D0
    IF (0 .GE. LPIVOT .OR. LPIVOT .GE. L1 .OR. L1 .GT. M) RETURN
    CL = ABS(U(1, LPIVOT))
    IF (MDE .EQ. 2) THEN
        ! Label 60 removed since the logic that would jump here was incorrect
    ELSE
        DO J = L1, M
            CL = MAX(ABS(U(1, J)), CL)
        END DO
        IF (CL == 0.0D0) RETURN
        CLINV = ONE / CL
        SM = (DBLE(U(1, LPIVOT)) * CLINV) ** 2
        DO J = L1, M
            SM = SM + (DBLE(U(1, J)) * CLINV) ** 2
        END DO
        SM1 = SM
        CL = CL * DSQRT(SM1)
        IF (U(1, LPIVOT) > 0.0D0) CL = -CL
        UP = U(1, LPIVOT) - CL
        U(1, LPIVOT) = CL
    END IF
    IF (NCV <= 0) RETURN
    B = DBLE(UP) * U(1, LPIVOT)
    IF (B == 0.0D0) RETURN
    B = ONE / B
    I2 = 1 - ICV + ICE * (LPIVOT - 1)
    INCR = ICE * (L1 - LPIVOT)
    DO J = 1, NCV
        I2 = I2 + ICV
        I3 = I2 + INCR
        I4 = I3
        SM = C(I2) * DBLE(UP)
        DO I = L1, M
            SM = SM + C(I3) * DBLE(U(1, I))
            I3 = I3 + ICE
        END DO
        IF (SM /= 0.0D0) THEN
            SM = SM * B
            C(I2) = C(I2) + SM * DBLE(UP)
            DO I = L1, M
                C(I4) = C(I4) + SM * DBLE(U(1, I))
                I4 = I4 + ICE
            END DO
        END IF
    END DO
END SUBROUTINE H12