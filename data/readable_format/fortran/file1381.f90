SUBROUTINE loop3_F77(N, x, y, a)
      INTEGER N
      REAL*8 x(N), y(N), a
      INTEGER i

      DO i=1,N
          y(i) = y(i) + a*x(i)
      END DO
      RETURN
      END

      SUBROUTINE loop3_F77Overhead(N, x, y, a)
      INTEGER N
      REAL*8 x(N), y(N), a
      RETURN
      END

! Main program or test harness for the subroutines
      PROGRAM testLoop3_F77
      IMPLICIT NONE
      INTEGER, PARAMETER :: N = 5
      REAL*8 :: x(N) = (/1.0, 2.0, 3.0, 4.0, 5.0/)
      REAL*8 :: y(N) = (/5.0, 4.0, 3.0, 2.0, 1.0/)
      REAL*8 :: a = 2.5
      INTEGER :: i

      CALL loop3_F77(N, x, y, a)

      PRINT *, 'After loop3_F77:'
      DO i = 1, N
          PRINT '(A, I1, A, F6.2)', 'y(', i, ') = ', y(i)
      END DO

      END PROGRAM testLoop3_F77