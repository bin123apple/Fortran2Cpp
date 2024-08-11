MODULE ILADLC_MOD
    IMPLICIT NONE
CONTAINS
    INTEGER FUNCTION ILADLC(M, N, A, LDA)
        INTEGER, INTENT(IN) :: M, N, LDA
        DOUBLE PRECISION, INTENT(IN) :: A(LDA, *)
        DOUBLE PRECISION :: ZERO
        INTEGER :: I

        ZERO = 0.0D+0

        IF (N == 0) THEN
            ILADLC = N
        ELSE IF (A(1, N) /= ZERO .OR. A(M, N) /= ZERO) THEN
            ILADLC = N
        ELSE
            DO ILADLC = N, 1, -1
                DO I = 1, M
                    IF (A(I, ILADLC) /= ZERO) RETURN
                END DO
            END DO
        END IF
    END FUNCTION ILADLC
END MODULE ILADLC_MOD

PROGRAM TestILADLC
    USE ILADLC_MOD
    IMPLICIT NONE
    DOUBLE PRECISION, ALLOCATABLE :: A(:,:)
    INTEGER :: result, m, n, lda

    ! Test 1: Empty matrix (0x0)
    m = 0
    n = 0
    lda = 0
    ALLOCATE(A(lda,n))
    result = ILADLC(m, n, A, lda)
    PRINT *, "Test 1 (Empty Matrix): ", result
    DEALLOCATE(A)

    ! Test 2: Matrix with all elements zero
    m = 3
    n = 4
    lda = 3
    ALLOCATE(A(lda,n))
    A = 0.0
    result = ILADLC(m, n, A, lda)
    PRINT *, "Test 2 (All Zeros): ", result
    DEALLOCATE(A)

    ! Test 3: Non-zero element at different positions
    m = 3
    n = 4
    lda = 3
    ALLOCATE(A(lda,n))
    A = 0.0
    A(3,1) = 1.0  ! Non-zero in 1st column
    result = ILADLC(m, n, A, lda)
    PRINT *, "Test 3 (Non-zero at A(3,1)): ", result
    A = 0.0
    A(1,4) = 1.0  ! Non-zero in last column
    result = ILADLC(m, n, A, lda)
    PRINT *, "Test 4 (Non-zero at A(1,4)): ", result
    DEALLOCATE(A)
END PROGRAM TestILADLC