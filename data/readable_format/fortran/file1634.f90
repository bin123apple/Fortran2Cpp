SUBROUTINE floop24_F77(N, x, a, b, c, d, y)
    INTEGER, INTENT(IN) :: N
    REAL*4, INTENT(OUT) :: x(N), y(N)
    REAL*4, INTENT(IN) :: a(N), b(N), c(N), d(N)
    INTEGER :: i

    DO i=1,N
        x(i) = a(i)*c(i) - b(i)*c(i)
        y(i) = a(i)*d(i) + b(i) + c(i)
    END DO
END SUBROUTINE floop24_F77

PROGRAM testFloop24
    IMPLICIT NONE
    INTEGER, PARAMETER :: N = 5
    REAL*4 :: x(N), a(N), b(N), c(N), d(N), y(N)
    INTEGER :: i

    ! Initialize arrays
    DO i = 1, N
        a(i) = 1.0
        b(i) = 2.0
        c(i) = 3.0
        d(i) = 4.0
    END DO

    ! Call the subroutine
    CALL floop24_F77(N, x, a, b, c, d, y)

    ! Print the results
    PRINT *, 'Results from Fortran test:'
    DO i = 1, N
        PRINT *, 'x(', i, ') = ', x(i), ', y(', i, ') = ', y(i)
    END DO
END PROGRAM testFloop24