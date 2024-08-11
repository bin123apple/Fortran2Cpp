PROGRAM TestFloop16
      IMPLICIT NONE
      INTEGER, PARAMETER :: N = 5
      REAL*4 :: y(N), x(N), a(N), b(N), c(N), u
      INTEGER :: i

      ! Initialize arrays a, b, and c, and scalar u
      DATA a /1.0, 2.0, 3.0, 4.0, 5.0/
      DATA b /1.0, 2.0, 3.0, 4.0, 5.0/
      DATA c /1.0, 2.0, 3.0, 4.0, 5.0/
      u = 2.0

      CALL floop16_F90(N, y, x, a, b, c, u)

      PRINT *, 'x:', (x(i), i=1,N)
      PRINT *, 'y:', (y(i), i=1,N)
      
      CONTAINS
      
      SUBROUTINE floop16_F90(N, y, x, a, b, c, u)
            INTEGER, INTENT(IN) :: N
            REAL*4, INTENT(OUT) :: y(N), x(N)
            REAL*4, INTENT(IN) :: a(N), b(N), c(N), u
            INTEGER :: i

            DO i = 1, N
                  x(i) = a(i) + b(i) + c(i)
                  y(i) = x(i) + c(i) + u
            END DO
      END SUBROUTINE floop16_F90
      
END PROGRAM TestFloop16