PROGRAM testDGENND
  IMPLICIT NONE
  DOUBLE PRECISION, ALLOCATABLE :: A(:,:)
  LOGICAL :: result
  INTEGER :: M, N, LDA

  INTERFACE
    LOGICAL FUNCTION DGENND(M, N, A, LDA)
      INTEGER :: M, N, LDA
      DOUBLE PRECISION :: A(LDA, *)
    END FUNCTION DGENND
  END INTERFACE

  ! Test 1: Matrix with positive diagonal
  M = 2
  N = 2
  LDA = 2
  ALLOCATE(A(LDA, N))
  A(1,1) = 1.0D0
  A(1,2) = 2.0D0
  A(2,1) = 3.0D0
  A(2,2) = 4.0D0
  result = DGENND(M, N, A, LDA)
  WRITE(*,*) 'Test 1 (Expected: T): ', result

  ! Test 2: Matrix with a negative diagonal element
  A(2,2) = -4.0D0
  result = DGENND(M, N, A, LDA)
  WRITE(*,*) 'Test 2 (Expected: F): ', result

  DEALLOCATE(A)

END PROGRAM testDGENND

LOGICAL FUNCTION DGENND (M, N, A, LDA)
  INTEGER M, N, LDA
  DOUBLE PRECISION A(LDA, *)
  DOUBLE PRECISION   ZERO
  PARAMETER          (ZERO = 0.0D0)
  INTEGER I, K
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