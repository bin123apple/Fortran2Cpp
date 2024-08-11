MODULE FloopsMod
    IMPLICIT NONE
CONTAINS
    SUBROUTINE floop23_F90(N, x, a, b, c, d, y)
        INTEGER, INTENT(IN) :: N
        REAL*4, INTENT(INOUT) :: x(N), a(N), b(N), c(N), d(N), y(N)
        INTEGER :: i

        DO i = 1, N
            x(i) = a(i) * b(i) + c(i) * d(i)
            y(i) = b(i) + d(i)
        END DO
    END SUBROUTINE floop23_F90
END MODULE FloopsMod

PROGRAM testFloops
    USE FloopsMod
    IMPLICIT NONE
    INTEGER :: N = 5
    REAL*4, ALLOCATABLE :: x(:), a(:), b(:), c(:), d(:), y(:)

    ALLOCATE(x(N), a(N), b(N), c(N), d(N), y(N))
    a = [1.0, 2.0, 3.0, 4.0, 5.0]
    b = [5.0, 4.0, 3.0, 2.0, 1.0]
    c = [1.0, 2.0, 3.0, 4.0, 5.0]
    d = [5.0, 4.0, 3.0, 2.0, 1.0]

    CALL floop23_F90(N, x, a, b, c, d, y)

    PRINT *, "Fortran Test Result: "
    PRINT *, "x =", x
    PRINT *, "y =", y

    DEALLOCATE(x, a, b, c, d, y)
END PROGRAM testFloops