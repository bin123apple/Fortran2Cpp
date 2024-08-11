SUBROUTINE floop17_F77(N, x, a, b, c, d)
      INTEGER i, N
      REAL*4 x(N), a(N), b(N), c(N), d(N)

      DO i=1,N
          x(i) = (a(i)+b(i))*(c(i)+d(i))
      END DO
      RETURN
      END


      PROGRAM TestFloop17
      IMPLICIT NONE
      INTEGER, PARAMETER :: N = 5
      REAL*4 :: x(N), a(N), b(N), c(N), d(N)
      INTEGER :: i

      ! Initialize the arrays
      DATA a /1.0, 2.0, 3.0, 4.0, 5.0/
      DATA b /2.0, 3.0, 4.0, 5.0, 6.0/
      DATA c /3.0, 4.0, 5.0, 6.0, 7.0/
      DATA d /4.0, 5.0, 6.0, 7.0, 8.0/

      ! Call the subroutine
      CALL floop17_F77(N, x, a, b, c, d)

      ! Print the results
      DO i = 1, N
        PRINT *, 'x(', i, ') = ', x(i)
      END DO
      END PROGRAM TestFloop17