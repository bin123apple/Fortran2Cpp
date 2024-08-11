PROGRAM TestILAZLC
  IMPLICIT NONE
  COMPLEX*16, ALLOCATABLE :: A(:,:)
  INTEGER :: M, N, LDA, result

  ! Test 1: 0x0 matrix
  M = 0
  N = 0
  LDA = 0
  ALLOCATE(A(LDA,N))
  result = ILAZLC(M, N, A, LDA)
  PRINT *, "Test 1 (0x0 matrix):", result
  DEALLOCATE(A)

  ! Test 2: Matrix with all elements being zero
  M = 2
  N = 3
  LDA = 2
  ALLOCATE(A(LDA,N))
  A = (0.0D0, 0.0D0)
  result = ILAZLC(M, N, A, LDA)
  PRINT *, "Test 2 (All zeros):", result
  DEALLOCATE(A)

  ! Test 3: Matrix with non-zero elements only in the last column
  M = 2
  N = 3
  LDA = 2
  ALLOCATE(A(LDA,N))
  A = (0.0D0, 0.0D0)
  A(1,3) = (1.0D0, 1.0D0)
  A(2,3) = (1.0D0, 1.0D0)
  result = ILAZLC(M, N, A, LDA)
  PRINT *, "Test 3 (Non-zeros in last column):", result
  DEALLOCATE(A)

  ! Additional tests can be added here
  
CONTAINS

  INTEGER FUNCTION ILAZLC( M, N, A, LDA )
    INTEGER, INTENT(IN) :: M, N, LDA
    COMPLEX*16, INTENT(IN) :: A(LDA, *)
    INTEGER :: I, J
    
    IF (N.EQ.0) THEN
       ILAZLC = 0
       RETURN
    END IF
    
    DO J = N, 1, -1
       DO I = 1, M
          IF (A(I, J) /= (0.0D0, 0.0D0)) THEN
             ILAZLC = J
             RETURN
          END IF
       END DO
    END DO
    
    ILAZLC = 0
  END FUNCTION ILAZLC

END PROGRAM TestILAZLC