PROGRAM testLoop8_F77
      IMPLICIT NONE
      INTEGER, PARAMETER :: N = 5
      REAL*8 :: a(N), x(N), u
      INTEGER :: i

      ! Initialize test data
      DATA a /1.0, 2.0, 4.0, 5.0, 10.0/
      u = 20.0

      CALL loop8_F77(N, a, x, u)

      ! Output results for manual verification
      PRINT *, 'Results:'
      DO i = 1, N
          PRINT '(A, I3, A, F6.2)', 'x(', i, ') = ', x(i)
      END DO

      END PROGRAM testLoop8_F77

      SUBROUTINE loop8_F77(N, a, x, u)
      INTEGER i, N
      REAL*8 a(N), x(N), u

      DO i=1,N
          x(i)=u/a(i)
      END DO
      RETURN
      END

      SUBROUTINE loop8_F77Overhead(N, a, x, u)
      INTEGER i, N
      REAL*8 a(N), x(N), u
      RETURN
      END