PROGRAM testCLAPMT
    IMPLICIT NONE
    COMPLEX, ALLOCATABLE :: X(:,:)
    INTEGER :: K(3)
    INTEGER :: M, N, LDX
    LOGICAL :: FORWRD

    ! Initialize matrix dimensions and permutation vector
    M = 2
    N = 3
    LDX = M
    K = (/ 3, 1, 2 /)
    ALLOCATE(X(LDX,N))

    ! Initialize matrix X
    X(1,1) = (1.0, 0.0)
    X(2,1) = (2.0, 0.0)
    X(1,2) = (3.0, 0.0)
    X(2,2) = (4.0, 0.0)
    X(1,3) = (5.0, 0.0)
    X(2,3) = (6.0, 0.0)

    ! Set direction of permutation
    FORWRD = .TRUE.

    CALL CLAPMT(FORWRD, M, N, X, LDX, K)

    ! Print the permuted matrix
    PRINT *, 'Permuted X:'
    DO N = 1, 3
        PRINT *, X(1,N), X(2,N)
    END DO
    
END PROGRAM testCLAPMT

SUBROUTINE CLAPMT(FORWRD, M, N, X, LDX, K)
    LOGICAL            FORWRD
    INTEGER            LDX, M, N
    INTEGER            K(*)
    COMPLEX            X(LDX,*)

    INTEGER            I, II, J, IN
    COMPLEX            TEMP

    IF (N.LE.1) RETURN

    DO I = 1, N
        K(I) = -K(I)
    END DO

    IF (FORWRD) THEN
        DO I = 1, N
            IF (K(I) > 0) GO TO 40

            J = I
            K(J) = -K(J)
            IN = K(J)

            DO WHILE (K(IN) <= 0)
                DO II = 1, M
                    TEMP = X(II, J)
                    X(II, J) = X(II, IN)
                    X(II, IN) = TEMP
                END DO
                K(IN) = -K(IN)
                J = IN
                IN = K(IN)
            END DO
40          CONTINUE
        END DO
    ELSE
        DO I = 1, N
            IF (K(I) > 0) GO TO 100

            K(I) = -K(I)
            J = K(I)
            DO WHILE (J /= I)
                DO II = 1, M
                    TEMP = X(II, I)
                    X(II, I) = X(II, J)
                    X(II, J) = TEMP
                END DO
                K(J) = -K(J)
                J = K(J)
            END DO
100     CONTINUE
        END DO
    END IF
END SUBROUTINE CLAPMT