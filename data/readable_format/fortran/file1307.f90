PROGRAM test_dger
  IMPLICIT NONE
  INTEGER, PARAMETER :: M=2, N=3, LDA=M
  REAL(KIND=8) :: A(LDA,N), X(M), Y(N), ALPHA
  INTEGER :: i, j

  ! Initialize matrix A, vectors X, Y and scalar ALPHA
  ALPHA = 2.0
  A = RESHAPE(SOURCE=[1.0, 2.0, 3.0, 4.0, 5.0, 6.0], SHAPE=[LDA, N])
  X = [1.0, 2.0]
  Y = [1.0, 2.0, 3.0]

  ! Call DGER subroutine
  CALL DGER(M, N, ALPHA, X, 1, Y, 1, A, LDA)

  ! Output the updated matrix A for verification
  PRINT *, "Updated matrix A:"
  DO i = 1, M
     PRINT "(3F6.2)", (A(i, j), j=1, N)
  END DO

CONTAINS

  SUBROUTINE DGER(M, N, ALPHA, X, INCX, Y, INCY, A, LDA)
    INTEGER, INTENT(IN) :: M, N, INCX, INCY, LDA
    REAL(KIND=8), INTENT(IN) :: ALPHA
    REAL(KIND=8), INTENT(IN) :: X(*), Y(*)
    REAL(KIND=8), INTENT(INOUT) :: A(LDA,*)
    INTEGER :: i, j

    ! Perform the rank-1 update A := alpha*x*y^T + A
    DO j = 1, N
      DO i = 1, M
        A(i,j) = A(i,j) + ALPHA*X(i)*Y(j)
      END DO
    END DO
  END SUBROUTINE DGER

END PROGRAM test_dger