PROGRAM TestDGENND
IMPLICIT NONE
DOUBLE PRECISION, ALLOCATABLE :: A(:,:)
LOGICAL :: result
INTEGER :: M, N, LDA

! Test case 1: Positive definite matrix
M = 2; N = 2; LDA = 2
ALLOCATE(A(LDA,N))
A(1,1) = 1.0D0; A(1,2) = 0.0D0
A(2,1) = 0.0D0; A(2,2) = 1.0D0
result = DGENND(M, N, A, LDA)
PRINT *, 'Test 1 (Positive definite): ', result

! Test case 2: Matrix with a negative diagonal element
A(1,1) = -1.0D0
result = DGENND(M, N, A, LDA)
PRINT *, 'Test 2 (Negative diagonal element): ', result

! Test case 3: Rectangular matrix (more rows)
DEALLOCATE(A)
M = 3; N = 2; LDA = 3
ALLOCATE(A(LDA,N))
A(1,1) = 1.0D0; A(1,2) = 0.0D0
A(2,1) = 0.0D0; A(2,2) = 1.0D0
A(3,1) = 0.0D0; A(3,2) = 0.0D0
result = DGENND(M, N, A, LDA)
PRINT *, 'Test 3 (Rectangular matrix): ', result

DEALLOCATE(A)

CONTAINS

LOGICAL FUNCTION DGENND(M, N, A, LDA)
INTEGER, INTENT(IN) :: M, N, LDA
DOUBLE PRECISION, INTENT(IN) :: A(LDA, *)
DOUBLE PRECISION :: ZERO
PARAMETER (ZERO = 0.0D0)
INTEGER :: I, K
INTRINSIC MIN

K = MIN(M, N)
DO I = 1, K
    IF (A(I, I) .LT. ZERO) THEN
        DGENND = .FALSE.
        RETURN
    END IF
END DO
DGENND = .TRUE.
RETURN
END FUNCTION DGENND

END PROGRAM TestDGENND