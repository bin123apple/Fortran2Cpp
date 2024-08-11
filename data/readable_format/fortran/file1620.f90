PROGRAM TestILADLR
  IMPLICIT NONE
  INTEGER :: M, N, LDA, result
  DOUBLE PRECISION, ALLOCATABLE :: A(:,:)

  INTERFACE
    INTEGER FUNCTION ILADLR(M, N, A, LDA)
      INTEGER, INTENT(IN) :: M, N, LDA
      DOUBLE PRECISION, INTENT(IN) :: A(LDA, *)
    END FUNCTION ILADLR
  END INTERFACE

  M = 4
  N = 3
  LDA = 4
  ALLOCATE(A(LDA,N))

  ! Initialize matrix A
  A = 0.0D+0
  A(1,1) = 1.0D+0
  A(2,3) = 2.0D+0
  A(3,2) = 3.0D+0
  ! The last row is all zeros

  result = ILADLR(M, N, A, LDA)
  PRINT *, "The last non-zero row is:", result

  DEALLOCATE(A)
END PROGRAM TestILADLR

! The ILADLR function definition
INTEGER FUNCTION ILADLR(M, N, A, LDA)
  INTEGER, INTENT(IN) :: M, N, LDA
  DOUBLE PRECISION, INTENT(IN) :: A(LDA, *)
  DOUBLE PRECISION :: ZERO
  PARAMETER (ZERO = 0.0D+0)
  INTEGER :: I, J

  IF (M == 0) THEN
     ILADLR = M
  ELSE IF (A(M, 1) /= ZERO .OR. A(M, N) /= ZERO) THEN
     ILADLR = M
  ELSE
     ILADLR = 0
     DO J = 1, N
        I = M
        DO WHILE ((A(MAX(I,1), J) == ZERO) .AND. (I >= 1))
           I = I - 1
        END DO
        ILADLR = MAX(ILADLR, I)
     END DO
  END IF
  RETURN
END FUNCTION ILADLR