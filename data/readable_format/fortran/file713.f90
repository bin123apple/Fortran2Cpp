MODULE ZLARTV_MOD
    IMPLICIT NONE
CONTAINS
    SUBROUTINE ZLARTV(N, X, INCX, Y, INCY, C, S, INCC)
        INTEGER, INTENT(IN) :: N, INCX, INCY, INCC
        DOUBLE PRECISION, INTENT(IN) :: C(*)
        COMPLEX*16, INTENT(INOUT) :: X(*), Y(*)
        COMPLEX*16, INTENT(IN) :: S(*)
        INTEGER :: I, IX, IY, IC
        COMPLEX*16 :: XI, YI
        
        IX = 1
        IY = 1
        IC = 1
        DO I = 1, N
            XI = X(IX)
            YI = Y(IY)
            X(IX) = C(IC)*XI + S(IC)*YI
            Y(IY) = C(IC)*YI - CONJG(S(IC))*XI
            IX = IX + INCX
            IY = IY + INCY
            IC = IC + INCC
        END DO
    END SUBROUTINE ZLARTV
END MODULE ZLARTV_MOD

PROGRAM TestZLARTV
    USE ZLARTV_MOD
    IMPLICIT NONE
    INTEGER, PARAMETER :: N = 5
    DOUBLE PRECISION, DIMENSION(N) :: C
    COMPLEX*16, DIMENSION(N) :: S, X, Y
    INTEGER :: i

    ! Initialize test data
    DO i = 1, N
        C(i) = DBLE(i)
        S(i) = CMPLX(DBLE(i), DBLE(N-i), KIND=8)
        X(i) = CMPLX(DBLE(N-i), DBLE(i), KIND=8)
        Y(i) = CMPLX(DBLE(i), DBLE(N-i+1), KIND=8)
    END DO

    ! Call the subroutine
    CALL ZLARTV(N, X, 1, Y, 1, C, S, 1)

    ! Output the results for inspection
    PRINT *, 'X:', X
    PRINT *, 'Y:', Y
END PROGRAM TestZLARTV