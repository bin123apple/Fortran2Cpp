SUBROUTINE OED__CTR_RS_EXPAND(N, NRS, NR, NS, X, Y)
    INTEGER, INTENT(IN) :: N, NRS, NR, NS
    DOUBLE PRECISION, INTENT(IN) :: X(N, NRS)
    DOUBLE PRECISION, INTENT(OUT) :: Y(N, NR, NS)
    INTEGER :: M, R, S, RS

    RS = NRS + 1

    DO S = NS, 1, -1
        DO R = NR, S+1, -1
            RS = RS - 1
            DO M = 1, N
                Y(M, R, S) = X(M, RS)
                Y(M, S, R) = X(M, RS)
            END DO
        END DO
        RS = RS - 1
        DO M = 1, N
            Y(M, S, S) = X(M, RS)
        END DO
    END DO
END SUBROUTINE

! Test program
PROGRAM testOED__CTR_RS_EXPAND
    IMPLICIT NONE
    INTEGER :: N, NRS, NR, NS, i, j, k
    DOUBLE PRECISION, ALLOCATABLE :: X(:,:), Y(:,:,:)

    N = 3
    NRS = 6
    NR = 3
    NS = 3

    ALLOCATE(X(N, NRS), Y(N, NR, NS))

    DO i = 1, N
        DO j = 1, NRS
            X(i, j) = REAL(i + j)
        END DO
    END DO

    CALL OED__CTR_RS_EXPAND(N, NRS, NR, NS, X, Y)

    DO k = 1, NS
        DO j = 1, NR
            DO i = 1, N
                PRINT *, 'Y(', i, ',', j, ',', k, ') = ', Y(i, j, k)
            END DO
        END DO
    END DO
END PROGRAM testOED__CTR_RS_EXPAND