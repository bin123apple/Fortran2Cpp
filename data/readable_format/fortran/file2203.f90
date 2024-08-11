PROGRAM test_floop13
    IMPLICIT NONE
    INTEGER :: N, i
    REAL*4 :: u
    REAL*4, DIMENSION(:), ALLOCATABLE :: y, x, a, b, c, d

    N = 5
    ALLOCATE(y(N), x(N), a(N), b(N), c(N), d(N))

    ! Initialize values
    u = 5.0
    DO i = 1, N
        a(i) = 1.0
        b(i) = 2.0
        c(i) = 3.0
        d(i) = 4.0
    END DO

    ! Call the subroutine
    CALL floop13_F90(N, y, x, a, b, c, d, u)

    ! Print results
    PRINT *, "Results for floop13_F90:"
    DO i = 1, N
        PRINT *, "x(", i, ") = ", x(i), ", y(", i, ") = ", y(i)
    END DO

    ! Call the overhead subroutine
    CALL floop13_F90Overhead(N, y, x, a, b, c, d, u)

    ! Print results (should be unchanged)
    PRINT *, "Results after floop13_F90Overhead (should be unchanged):"
    DO i = 1, N
        PRINT *, "x(", i, ") = ", x(i), ", y(", i, ") = ", y(i)
    END DO

    ! Clean up
    DEALLOCATE(y, x, a, b, c, d)

CONTAINS

    SUBROUTINE floop13_F90(N, y, x, a, b, c, d, u)
        INTEGER :: N, i
        REAL*4 :: y(N), x(N), a(N), b(N), c(N), d(N), u

        x = a + b + c + d
        y = u + d
    END SUBROUTINE floop13_F90

    SUBROUTINE floop13_F90Overhead(N, y, x, a, b, c, d, u)
        INTEGER :: N, i
        REAL*4 :: y(N), x(N), a(N), b(N), c(N), d(N), u

        ! This subroutine intentionally does nothing
    END SUBROUTINE floop13_F90Overhead

END PROGRAM test_floop13