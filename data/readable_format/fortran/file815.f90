PROGRAM TestCGENND
    IMPLICIT NONE
    INTEGER :: M, N, LDA
    COMPLEX :: A(2,2)
    LOGICAL :: result

    ! Test 1: 2x2 identity matrix
    M = 2
    N = 2
    LDA = 2
    A(1,1) = (1.0, 0.0)
    A(1,2) = (0.0, 0.0)
    A(2,1) = (0.0, 0.0)
    A(2,2) = (1.0, 0.0)

    result = CGENND(M, N, A, LDA)
    PRINT *, "Test 1 (Expect .TRUE.): ", result

    ! Test 2: 2x2 matrix with a negative real part on the diagonal
    A(1,1) = (-1.0, 0.0)
    A(1,2) = (0.0, 0.0)
    A(2,1) = (0.0, 0.0)
    A(2,2) = (1.0, 0.0)

    result = CGENND(M, N, A, LDA)
    PRINT *, "Test 2 (Expect .FALSE.): ", result

CONTAINS

    LOGICAL FUNCTION CGENND(M, N, A, LDA)
        INTEGER, INTENT(IN) :: M, N, LDA
        COMPLEX, INTENT(IN) :: A(LDA, *)
        INTEGER :: I, K
        COMPLEX :: AII

        K = MIN(M, N)
        DO I = 1, K
            AII = A(I, I)
            IF (REAL(AII) < 0.0 .OR. AIMAG(AII) /= 0.0) THEN
                CGENND = .FALSE.
                RETURN
            END IF
        END DO
        CGENND = .TRUE.
    END FUNCTION CGENND

END PROGRAM TestCGENND