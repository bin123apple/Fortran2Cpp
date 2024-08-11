MODULE initialdata_mod
    IMPLICIT NONE
CONTAINS
    SUBROUTINE initialdata(Nx, Ny, x, y, u, uold)
        INTEGER, INTENT(IN) :: Nx, Ny
        REAL(KIND=8), DIMENSION(Nx), INTENT(IN) :: x
        REAL(KIND=8), DIMENSION(Ny), INTENT(IN) :: y
        COMPLEX(KIND=8), DIMENSION(Nx, Ny), INTENT(OUT) :: u, uold
        INTEGER :: i, j

        ! Initialize matrices
        DO j = 1, Ny
            DO i = 1, Nx
                u(i,j) = 0.5d0 * EXP(-1.0d0 * (x(i)**2 + y(j)**2)) * SIN(10.0d0 * x(i) + 12.0d0 * y(j))
                uold(i,j) = u(i,j)
            END DO
        END DO
    END SUBROUTINE initialdata
END MODULE initialdata_mod

PROGRAM test_initialdata
    USE initialdata_mod
    IMPLICIT NONE
    INTEGER, PARAMETER :: Nx=5, Ny=4
    REAL(KIND=8), DIMENSION(Nx) :: x
    REAL(KIND=8), DIMENSION(Ny) :: y
    COMPLEX(KIND=8), DIMENSION(Nx, Ny) :: u, uold
    INTEGER :: i, j

    ! Initialize test data
    DO i = 1, Nx
        x(i) = REAL(i, KIND=8)
    END DO
    DO j = 1, Ny
        y(j) = REAL(j, KIND=8)
    END DO

    CALL initialdata(Nx, Ny, x, y, u, uold)

    PRINT *, "Matrix u:"
    DO j = 1, Ny
        DO i = 1, Nx
            PRINT '(2F8.4)', REAL(u(i,j)), AIMAG(u(i,j))
        END DO
        PRINT *, " "
    END DO

    PRINT *, "Matrix uold:"
    DO j = 1, Ny
        DO i = 1, Nx
            PRINT '(2F8.4)', REAL(uold(i,j)), AIMAG(uold(i,j))
        END DO
        PRINT *, " "
    END DO
END PROGRAM test_initialdata