PROGRAM Main
  IMPLICIT NONE
  INTEGER :: M, N, LDA, result
  INTEGER, PARAMETER :: MAX_SIZE = 100
  DOUBLE PRECISION, ALLOCATABLE :: A(:,:)

  ! Example parameters - adjust as necessary
  M = 3
  N = 2
  LDA = 3
  ALLOCATE(A(LDA,N))

  ! Initialize the matrix A with some values for testing
  A = 0.0
  A(3,1) = 0.0
  A(3,2) = 0.0

  result = WFN1_AD_ILADLR(M, N, A, LDA)
  PRINT *, "Result = ", result

  DEALLOCATE(A)

CONTAINS

  INTEGER FUNCTION WFN1_AD_ILADLR(M, N, A, LDA)
    INTEGER, INTENT(IN) :: M, N, LDA
    DOUBLE PRECISION, INTENT(IN) :: A(LDA,*)
    INTEGER :: I, J
    DOUBLE PRECISION :: ZERO
    ZERO = 0.0D+0

    IF (M == 0) THEN
       WFN1_AD_ILADLR = M
       RETURN
    ELSE IF (A(M, 1) /= ZERO .OR. A(M, N) /= ZERO) THEN
       WFN1_AD_ILADLR = M
       RETURN
    ELSE
       WFN1_AD_ILADLR = 0
       DO J = 1, N
          I = M
          DO WHILE (A(MAX(I,1),J) == ZERO .AND. I >= 1)
             I = I - 1
          END DO
          WFN1_AD_ILADLR = MAX(WFN1_AD_ILADLR, I)
       END DO
    END IF
  END FUNCTION WFN1_AD_ILADLR

END PROGRAM Main