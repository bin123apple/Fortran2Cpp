PROGRAM testLoop4
  IMPLICIT NONE
  INTEGER, PARAMETER :: N = 5
  INTEGER :: i
  REAL*8 :: x(N), a(N), b(N)

  ! Initialize test data
  DO i = 1, N
    a(i) = i * 1.0
    b(i) = i * 2.0
  END DO

  ! Call the subroutine
  CALL loop4_F77(1, N, x, a, b)

  ! Print results
  DO i = 1, N
    PRINT *, 'x(', i, ') = ', x(i)
  END DO

  CONTAINS

    SUBROUTINE loop4_F77(niters, N, x, a, b)
      INTEGER, INTENT(IN) :: niters, N
      REAL*8, INTENT(INOUT) :: x(N)
      REAL*8, INTENT(IN) :: a(N), b(N)
      INTEGER :: i, iter

      DO iter = 1, niters
        DO i = 1, N
          x(i) = a(i) + b(i)
        END DO
      END DO
    END SUBROUTINE loop4_F77

END PROGRAM testLoop4