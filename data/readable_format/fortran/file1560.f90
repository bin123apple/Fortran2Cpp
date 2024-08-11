PROGRAM testILADLC
  IMPLICIT NONE
  INTEGER :: M, N, result
  DOUBLE PRECISION, ALLOCATABLE :: A(:,:)

  ! Test Case 1: A 3x3 matrix with last non-zero column at 2
  M = 3
  N = 3
  ALLOCATE(A(M,N))
  A = RESHAPE([0.0D0, 0.0D0, 0.0D0, &
               0.0D0, 2.0D0, 0.0D0, &
               0.0D0, 3.0D0, 0.0D0], SHAPE(A))
  result = ILADLC(M, N, A, M)
  PRINT *, "Test Case 1: Expected 2, Got ", result
  DEALLOCATE(A)

  ! Test Case 2: A 2x2 matrix with all zeros
  M = 2
  N = 2
  ALLOCATE(A(M,N))
  A = 0.0D0
  result = ILADLC(M, N, A, M)
  PRINT *, "Test Case 2: Expected 0, Got ", result
  DEALLOCATE(A)

CONTAINS

  INTEGER FUNCTION ILADLC( M, N, A, LDA )
    INTEGER, INTENT(IN) :: M, N, LDA
    DOUBLE PRECISION, INTENT(IN) :: A(LDA, *)
    DOUBLE PRECISION :: ZERO
    INTEGER :: I

    ZERO = 0.0D0
    
    IF ( N == 0 ) THEN
       ILADLC = 0
       RETURN
    ELSE IF ( A(1, N) /= ZERO .OR. A(M, N) /= ZERO ) THEN
       ILADLC = N
       RETURN
    ELSE
       DO ILADLC = N, 1, -1
          DO I = 1, M
             IF ( A(I, ILADLC) /= ZERO ) THEN
                RETURN
             END IF
          END DO
       END DO
       ILADLC = 0
    END IF
  END FUNCTION ILADLC

END PROGRAM testILADLC