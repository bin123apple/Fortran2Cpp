PROGRAM TestSwap
  IMPLICIT NONE
  INTEGER, PARAMETER :: n = 5
  REAL :: x(n) = [1.0, 2.0, 3.0, 4.0, 5.0]
  REAL :: y(n) = [5.0, 4.0, 3.0, 2.0, 1.0]
  INTEGER :: i

  CALL V7SWP(n, x, y)

  PRINT *, 'Array X after swap:'
  DO i = 1, n
     PRINT *, x(i)
  END DO

  PRINT *, 'Array Y after swap:'
  DO i = 1, n
     PRINT *, y(i)
  END DO
END PROGRAM TestSwap

SUBROUTINE V7SWP(N, X, Y)
  INTEGER N
  REAL X(N), Y(N)
  INTEGER I
  REAL T
  DO I = 1, N
     T = X(I)
     X(I) = Y(I)
     Y(I) = T
  END DO
END SUBROUTINE V7SWP