PROGRAM testILAZLR
  IMPLICIT NONE
  INTEGER, PARAMETER :: M = 4, N = 3, LDA = 4
  COMPLEX*16, DIMENSION(LDA,N) :: A
  INTEGER :: result

  INTERFACE
    INTEGER FUNCTION ILAZLR(M, N, A, LDA)
      INTEGER, INTENT(IN) :: M, N, LDA
      COMPLEX*16, INTENT(IN) :: A(LDA, *)
    END FUNCTION ILAZLR
  END INTERFACE

  ! Initialize matrix A
  A = RESHAPE((/(0.0D0, 0.0D0), (2.0D0, 3.0D0), (0.0D0, 0.0D0), (0.0D0, 0.0D0), &
               (0.0D0, 0.0D0), (0.0D0, 0.0D0), (4.0D0, 5.0D0), (0.0D0, 0.0D0), &
               (0.0D0, 0.0D0), (0.0D0, 0.0D0), (0.0D0, 0.0D0), (6.0D0, 7.0D0) /), (/LDA, N/))

  result = ILAZLR(M, N, A, LDA)

  PRINT *, "Test Result: ", result
  IF (result == 2) THEN
    PRINT *, "Test Passed"
  ELSE
    PRINT *, "Test Failed"
  END IF
END PROGRAM testILAZLR

INTEGER FUNCTION ILAZLR(M, N, A, LDA)
  IMPLICIT NONE
  INTEGER, INTENT(IN) :: M, N, LDA
  COMPLEX*16, INTENT(IN) :: A(LDA, *)
  COMPLEX*16       ZERO
  PARAMETER (ZERO = (0.0D0, 0.0D0))
  INTEGER I, J

  IF (M.EQ.0 .OR. A(M, 1).NE.ZERO .OR. A(M, N).NE.ZERO) THEN
    ILAZLR = M
  ELSE
    ILAZLR = 0
    DO J = 1, N
      DO I = M, 1, -1
        IF (A(I, J).NE.ZERO) THEN
          ILAZLR = MAX(ILAZLR, I)
          EXIT
        END IF
      END DO
    END DO
  END IF
  RETURN
END FUNCTION ILAZLR