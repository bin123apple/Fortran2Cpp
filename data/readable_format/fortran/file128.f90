! Define the subroutines first
SUBROUTINE loop12_F77(N, y, a, x, b, c, d, u)
    INTEGER, INTENT(IN) :: N
    REAL(8), INTENT(INOUT) :: y(N), x(N)
    REAL(8), INTENT(IN) :: a(N), b(N), c(N), d(N), u
    INTEGER :: i

    DO i = 1, N
        y(i) = u + a(i)
        x(i) = a(i) + b(i) + c(i) + d(i)
    END DO
END SUBROUTINE loop12_F77

SUBROUTINE loop12_F77Overhead(N, y, a, x, b, c, d, u)
    INTEGER, INTENT(IN) :: N
    REAL(8), INTENT(INOUT) :: y(N), x(N)
    REAL(8), INTENT(IN) :: a(N), b(N), c(N), d(N), u
    ! This subroutine is intentionally left empty to match the original example
END SUBROUTINE loop12_F77Overhead

! Your program to test the subroutines
PROGRAM testLoops
    IMPLICIT NONE
    INTEGER, PARAMETER :: N = 5
    REAL(8) :: y(N), a(N), x(N), b(N), c(N), d(N), u
    INTEGER :: i

    ! Initialize arrays
    u = 1.0
    DO i = 1, N
        a(i) = i * 1.0
        b(i) = i * 2.0
        c(i) = i * 3.0
        d(i) = i * 4.0
    END DO

    ! Call the subroutine
    CALL loop12_F77(N, y, a, x, b, c, d, u)

    ! Output results for verification
    DO i = 1, N
        PRINT *, 'y(', i, ') = ', y(i), ', x(', i, ') = ', x(i)
    END DO
END PROGRAM testLoops