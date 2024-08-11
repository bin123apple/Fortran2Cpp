! Corrected Fortran Program with Unit Test
PROGRAM TestLoop16
IMPLICIT NONE
INTEGER, PARAMETER :: N = 5
REAL*8 :: x(N), a(N), b(N), c(N), y(N), u
INTEGER :: i

! Function declaration
EXTERNAL loop16_F77

! Initialize arrays
u = 2.0
DO i = 1, N
    a(i) = 1.0 * i
    b(i) = 2.0 * i
    c(i) = 3.0 * i
END DO

CALL loop16_F77(N, x, a, b, c, y, u)

! Check results and display output
DO i = 1, N
    PRINT *, "y(", i, ") = ", y(i)
END DO

END PROGRAM TestLoop16

SUBROUTINE loop16_F77(N, x, a, b, c, y, u)
INTEGER, INTENT(IN) :: N
REAL*8, INTENT(INOUT) :: x(N), a(N), b(N), c(N), y(N)
REAL*8, INTENT(IN) :: u
INTEGER :: i

DO i = 1, N
    x(i) = a(i) + b(i) + c(i)
    y(i) = x(i) + c(i) + u
END DO
END SUBROUTINE loop16_F77