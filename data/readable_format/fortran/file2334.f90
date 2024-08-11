PROGRAM TestLUBKSB
    IMPLICIT NONE
    INTEGER, PARAMETER :: N = 3, NP = 3
    DOUBLE PRECISION, DIMENSION(NP, NP) :: A
    INTEGER, DIMENSION(N) :: INDX
    DOUBLE PRECISION, DIMENSION(N) :: B
    INTEGER :: I

    ! Initialize matrix A
    DATA A /2.0, -1.0, 0.0,  &
           -1.0, 2.0, -1.0, &
           0.0, -1.0, 2.0/
    
    ! Initialize index vector INDX
    DATA INDX /1, 2, 3/
    
    ! Initialize vector B
    DATA B /1.0, 2.0, 3.0/

    CALL LUBKSB(A, N, NP, INDX, B)

    PRINT *, 'Solution:'
    DO I = 1, N
        PRINT *, B(I)
    END DO
END PROGRAM TestLUBKSB

SUBROUTINE LUBKSB(A, N, NP, INDX, B)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: N, NP
    DOUBLE PRECISION, INTENT(INOUT), DIMENSION(NP, NP) :: A
    INTEGER, INTENT(IN), DIMENSION(N) :: INDX
    DOUBLE PRECISION, INTENT(INOUT), DIMENSION(N) :: B
    INTEGER :: I, J, II, LL
    DOUBLE PRECISION :: SUM

    II = 0
    DO I = 1, N
        LL = INDX(I)
        SUM = B(LL)
        B(LL) = B(I)
        IF (II /= 0) THEN
            DO J = II, I - 1
                SUM = SUM - A(I, J) * B(J)
            END DO
        ELSE IF (SUM /= 0.0) THEN
            II = I
        END IF
        B(I) = SUM
    END DO

    DO I = N, 1, -1
        SUM = B(I)
        IF (I < N) THEN
            DO J = I + 1, N
                SUM = SUM - A(I, J) * B(J)
            END DO
        END IF
        B(I) = SUM / A(I, I)
    END DO
END SUBROUTINE LUBKSB