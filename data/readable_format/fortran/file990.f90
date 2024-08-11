PROGRAM TestLoop18
    IMPLICIT NONE

    REAL*8, ALLOCATABLE :: x(:), a(:), b(:)
    INTEGER :: N
    REAL*8 :: u, v
    INTEGER :: i

    N = 5
    ALLOCATE(x(N), a(N), b(N))

    ! Initialize test data
    u = 3.0
    v = 4.0
    DO i = 1, N
        a(i) = 1.0
        b(i) = 2.0
    END DO

    ! Call the subroutine under test
    CALL loop18_F77(N, x, a, b, u, v)

    ! Output the results for manual verification
    DO i = 1, N
        PRINT *, "x(", i, ") = ", x(i)
    END DO

    DEALLOCATE(x, a, b)

END PROGRAM TestLoop18

SUBROUTINE loop18_F77(N, x, a, b, u, v)
    INTEGER, INTENT(IN) :: N
    REAL*8, INTENT(OUT) :: x(N)
    REAL*8, INTENT(IN) :: a(N), b(N), u, v
    INTEGER :: i

    DO i=1,N
        x(i)=(u+a(i))*(v+b(i))
    END DO

END SUBROUTINE loop18_F77

SUBROUTINE loop18_F77Overhead(N, x, a, b, u, v)
    ! This subroutine is intentionally left empty as per the original Fortran code provided
    INTEGER, INTENT(IN) :: N
    REAL*8, INTENT(OUT) :: x(N)
    REAL*8, INTENT(IN) :: a(N), b(N), u, v

END SUBROUTINE loop18_F77Overhead