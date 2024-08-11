! Define the subroutines first
SUBROUTINE floop19_F77(N, y, x, a, b, u, v)
    INTEGER, INTENT(IN) :: N
    REAL*4, INTENT(OUT) :: y(N), x(N)
    REAL*4, INTENT(IN) :: a(N), b(N), u, v
    INTEGER :: i

    DO i = 1, N
        x(i) = u * a(i)
        y(i) = v * b(i)
    END DO
END SUBROUTINE floop19_F77

SUBROUTINE floop19_F77Overhead(N, y, x, a, b, u, v)
    INTEGER, INTENT(IN) :: N
    REAL*4, INTENT(OUT) :: y(N), x(N)
    REAL*4, INTENT(IN) :: a(N), b(N), u, v
    ! This subroutine intentionally left blank
END SUBROUTINE floop19_F77Overhead

! Main program starts here
PROGRAM TestFloop19
    IMPLICIT NONE
    INTEGER, PARAMETER :: N = 5
    REAL*4 :: y(N), x(N), a(N) = (/1.0, 2.0, 3.0, 4.0, 5.0/), b(N) = (/5.0, 4.0, 3.0, 2.0, 1.0/)
    REAL*4 :: u = 2.0, v = 3.0
    INTEGER :: i

    ! Call the subroutine
    CALL floop19_F77(N, y, x, a, b, u, v)

    ! Print the results for verification
    PRINT *, 'x: '
    DO i = 1, N
        PRINT *, x(i)
    END DO

    PRINT *, 'y: '
    DO i = 1, N
        PRINT *, y(i)
    END DO
END PROGRAM TestFloop19