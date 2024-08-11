MODULE ILACLR_MOD
  IMPLICIT NONE
CONTAINS
  INTEGER FUNCTION ILACLR(M, N, A, LDA)
    INTEGER, INTENT(IN) :: M, N, LDA
    COMPLEX, INTENT(IN) :: A(LDA, *)
    COMPLEX :: ZERO
    INTEGER :: I, J

    ZERO = (0.0E+0, 0.0E+0)

    IF (M == 0) THEN
      ILACLR = M
    ELSE IF (A(M, 1) /= ZERO .OR. A(M, N) /= ZERO) THEN
      ILACLR = M
    ELSE
      ILACLR = 0
      DO J = 1, N
        I = M
        DO WHILE (A(MAX(I,1), J) == ZERO .AND. I >= 1)
          I = I - 1
        END DO
        ILACLR = MAX(ILACLR, I)
      END DO
    END IF
  END FUNCTION ILACLR
END MODULE ILACLR_MOD

PROGRAM TEST_ILACLR
  USE ILACLR_MOD
  IMPLICIT NONE
  INTEGER :: M, N, LDA, result
  COMPLEX, ALLOCATABLE :: A(:,:)

  ! Test case 1
  M = 3
  N = 3
  LDA = 3
  ALLOCATE(A(LDA,N))
  A = 0.0
  result = ILACLR(M, N, A, LDA)
  PRINT *, "Test case 1 result: ", result

  ! Test case 2
  A(LDA, 1) = (1.0, 0.0)
  result = ILACLR(M, N, A, LDA)
  PRINT *, "Test case 2 result: ", result

  ! Test case 3
  A = 0.0
  A(LDA, N) = (1.0, 0.0)
  result = ILACLR(M, N, A, LDA)
  PRINT *, "Test case 3 result: ", result

  ! Test case 4
  A = 0.0
  A(LDA-1, 2) = (1.0, 0.0)
  result = ILACLR(M, N, A, LDA)
  PRINT *, "Test case 4 result: ", result

  DEALLOCATE(A)
END PROGRAM TEST_ILACLR