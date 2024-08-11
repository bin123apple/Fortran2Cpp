SUBROUTINE loop12_F77(N, y, x, a, b, c, d, u)
      INTEGER i, N
      REAL*8 y(N), x(N), a(N), b(N), c(N), d(N), u

      DO i=1,N
          y(i) = u+a(i)
          x(i) = a(i)+b(i)+c(i)+d(i)
      END DO
      RETURN
      END

      SUBROUTINE loop12_F77Overhead(N, y, x, a, b, c, d, u)
      INTEGER i, N
      REAL*8 y(N), x(N), a(N), b(N), c(N), d(N), u
      RETURN
      END

      PROGRAM test
      IMPLICIT NONE
      INTEGER, PARAMETER :: N = 5
      REAL*8 y(N), x(N), a(N), b(N), c(N), d(N)
      REAL*8 u
      INTEGER i

      ! Initialize test data
      u = 2.0
      DO i = 1, N
          a(i) = i * 1.0
          b(i) = i * 2.0
          c(i) = i * 3.0
          d(i) = i * 4.0
      END DO

      ! Call the subroutine
      CALL loop12_F77(N, y, x, a, b, c, d, u)

      ! Output results (for demonstration; in practice, verify results)
      DO i = 1, N
          PRINT *, "y(", i, ") = ", y(i), ", x(", i, ") = ", x(i)
      END DO

      END PROGRAM test