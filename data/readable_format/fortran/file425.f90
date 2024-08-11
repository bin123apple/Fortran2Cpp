PROGRAM TestILAZLC
  IMPLICIT NONE
  INTEGER :: M, N, LDA, result
  COMPLEX(KIND=8) :: A(10, 10)
  COMPLEX(KIND=8), PARAMETER :: ZERO = (0.0D0, 0.0D0)
  INTEGER :: i, j

  M = 10
  N = 10
  LDA = 10

  ! Initialize the matrix to zero
  DO j = 1, N
     DO i = 1, M
        A(i, j) = ZERO
     END DO
  END DO

  ! Test Case 1: All zero matrix
  result = ILAZLC(M, N, A, LDA)
  PRINT *, "Test Case 1: Expected 0, got ", result

  ! Test Case 2: Last column has a non-zero element
  A(5, 10) = (1.0D0, 0.0D0)
  result = ILAZLC(M, N, A, LDA)
  PRINT *, "Test Case 2: Expected 10, got ", result

  ! Test Case 3: 5th column is the last with a non-zero element
  A(5, 10) = ZERO
  A(3, 5) = (1.0D0, 0.0D0)
  result = ILAZLC(M, N, A, LDA)
  PRINT *, "Test Case 3: Expected 5, got ", result

CONTAINS

  INTEGER FUNCTION ILAZLC(M, N, A, LDA)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: M, N, LDA
    COMPLEX(KIND=8), INTENT(IN) :: A(LDA, *)
    COMPLEX(KIND=8), PARAMETER :: ZERO = (0.0D0, 0.0D0)
    INTEGER :: I

    IF (N == 0) THEN
       ILAZLC = 0
       RETURN
    END IF

    DO I = N, 1, -1
       IF (ANY(A(:, I) /= ZERO)) THEN
          ILAZLC = I
          RETURN
       END IF
    END DO

    ILAZLC = 0
  END FUNCTION ILAZLC

END PROGRAM TestILAZLC