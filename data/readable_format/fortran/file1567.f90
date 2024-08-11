PROGRAM TestTridag
  IMPLICIT NONE
  INTEGER, PARAMETER :: n = 4
  REAL :: a(n), b(n), c(n), r(n), u(n)
  INTEGER :: i

  ! Initialize the vectors for a known tridiagonal system
  a = (/0.0, -1.0, -1.0, -1.0/)
  b = (/4.0,  4.0,  4.0,  4.0/)
  c = (/-1.0, -1.0, -1.0, 0.0/)
  r = (/5.0,  5.0,  10.0, 3.0/)
  
  ! Call the tridag subroutine
  CALL tridag(a, b, c, r, u, n)
  
  ! Print the results
  PRINT *, 'Results:'
  DO i = 1, n
    PRINT *, 'u(', i, ') = ', u(i)
  END DO

  CONTAINS

    SUBROUTINE tridag(a, b, c, r, u, n)
      INTEGER, INTENT(IN) :: n
      REAL, INTENT(IN) :: a(n), b(n), c(n), r(n)
      REAL, INTENT(OUT) :: u(n)
      REAL :: gam(n)
      REAL :: bet
      INTEGER :: j

      IF (b(1) == 0.0) THEN
        PRINT *, 'tridag: rewrite equations'
        STOP 
      END IF

      bet = b(1)
      u(1) = r(1) / bet

      DO j = 2, n
        gam(j) = c(j-1) / bet
        bet = b(j) - a(j) * gam(j)
        IF (bet == 0.0) THEN
          PRINT *, 'tridag failed'
          STOP
        END IF
        u(j) = (r(j) - a(j)*u(j-1)) / bet
      END DO

      DO j = n-1, 1, -1
        u(j) = u(j) - gam(j+1)*u(j+1)
      END DO
    END SUBROUTINE tridag

END PROGRAM TestTridag