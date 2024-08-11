SUBROUTINE DAAT(A, X, N)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: N
    REAL*8, INTENT(IN) :: A(N,N)
    REAL*8, INTENT(OUT) :: X(N,N)
    REAL*8 :: R
    INTEGER :: I, J, K

    DO I = 1, N
        DO J = 1, N
            R = 0.0D0
            DO K = 1, N
                R = R + A(I,K) * A(K,J) ! Correcting the multiply operation for A by A^T
            END DO
            X(I,J) = R
        END DO
    END DO
END SUBROUTINE DAAT

PROGRAM TestDAAT
    IMPLICIT NONE
    INTEGER :: n
    REAL*8, ALLOCATABLE :: A(:,:), X(:,:)
    
    ! Test 1: 2x2 Matrix
    n = 2
    ALLOCATE(A(n,n), X(n,n))
    A = RESHAPE([1.0D0, 2.0D0, 3.0D0, 4.0D0], [n, n])
    CALL DAAT(A, X, n)
    PRINT *, 'Test 1: 2x2 Matrix'
    PRINT *, X
    
    DEALLOCATE(A, X)

    ! Test 2: 3x3 Matrix
    n = 3
    ALLOCATE(A(n,n), X(n,n))
    A = RESHAPE([1.0D0, 2.0D0, 3.0D0, 4.0D0, 5.0D0, 6.0D0, 7.0D0, 8.0D0, 9.0D0], [n, n])
    CALL DAAT(A, X, n)
    PRINT *, 'Test 2: 3x3 Matrix'
    PRINT *, X

    DEALLOCATE(A, X)
END PROGRAM TestDAAT