PROGRAM TestFloop8_F77
      IMPLICIT NONE
      INTEGER, PARAMETER :: N = 5
      REAL*4 :: a(N), x(N), u
      INTEGER :: i

      ! Initialize test data
      DATA a /1.0, 2.0, 3.0, 4.0, 5.0/
      u = 10.0

      CALL floop8_F77(N, a, x, u)

      ! Print results and check correctness
      PRINT *, 'Testing floop8_F77...'
      DO i = 1, N
          PRINT *, 'x(', i, ') = ', x(i)
          IF (ABS(x(i) - (u / a(i))) > 1E-6) THEN
              PRINT *, 'Test failed.'
              STOP
          END IF
      END DO
      PRINT *, 'Test passed.'

      END PROGRAM TestFloop8_F77

      SUBROUTINE floop8_F77(N, a, x, u)
            INTEGER i, N
            REAL*4 a(N), x(N), u

            DO i=1,N
                x(i) = u/a(i)
            END DO
            RETURN
      END