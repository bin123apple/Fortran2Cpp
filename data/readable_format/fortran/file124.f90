SUBROUTINE loop22_F77(N, x, a, b, c, d)
      INTEGER :: N, i
      REAL*8 :: x(N), a(N), b(N), c(N), d(N)

      DO i = 1, N
          x(i) = x(i) + a(i) * b(i) + c(i) * d(i)
      END DO
      END SUBROUTINE loop22_F77

      SUBROUTINE loop22_F77Overhead(N, x, a, b, c, d)
      INTEGER :: N, i
      REAL*8 :: x(N), a(N), b(N), c(N), d(N)
      ! This subroutine intentionally left blank
      END SUBROUTINE loop22_F77Overhead

      PROGRAM testLoop22
      IMPLICIT NONE
      INTEGER :: N = 5, i
      REAL*8 :: x(5) = [1.0, 2.0, 3.0, 4.0, 5.0]
      REAL*8 :: a(5) = [2.0, 2.0, 2.0, 2.0, 2.0]
      REAL*8 :: b(5) = [1.0, 1.0, 1.0, 1.0, 1.0]
      REAL*8 :: c(5) = [0.5, 0.5, 0.5, 0.5, 0.5]
      REAL*8 :: d(5) = [2.0, 2.0, 2.0, 2.0, 2.0]

      CALL loop22_F77(N, x, a, b, c, d)

      DO i = 1, N
          PRINT *, "x(", i, ") = ", x(i)
      END DO
      END PROGRAM testLoop22