PROGRAM TestInitialData
    IMPLICIT NONE
    INTEGER, PARAMETER :: Nx=10, Ny=10, Nz=10
    REAL(KIND=8), DIMENSION(Nx) :: x
    REAL(KIND=8), DIMENSION(Ny) :: y
    REAL(KIND=8), DIMENSION(Nz) :: z
    COMPLEX(KIND=8), DIMENSION(Nx,Ny,Nz) :: u, uold
    INTEGER :: i, j, k

    ! Initialize x, y, z arrays
    DO i = 1, Nx
        x(i) = REAL(i, KIND=8) / 10.0
        y(i) = REAL(i, KIND=8) / 10.0
        z(i) = REAL(i, KIND=8) / 10.0
    END DO

    CALL initialdata(Nx, Ny, Nz, x, y, z, u, uold)

    ! Example Test: Check if u and uold are identical
    DO k = 1, Nz
        DO j = 1, Ny
            DO i = 1, Nx
                IF (u(i,j,k) /= uold(i,j,k)) THEN
                    PRINT *, "Test Failed at: ", i, j, k
                    STOP
                END IF
            END DO
        END DO
    END DO

    PRINT *, "All tests passed."

CONTAINS

    SUBROUTINE initialdata(Nx,Ny,Nz,x,y,z,u,uold)
    IMPLICIT NONE
    INTEGER(KIND=4), INTENT(IN) :: Nx,Ny,Nz
    REAL(KIND=8), DIMENSION(1:NX), INTENT(IN) :: x
    REAL(KIND=8), DIMENSION(1:NY), INTENT(IN) :: y
    REAL(KIND=8), DIMENSION(1:NZ), INTENT(IN) :: z
    COMPLEX(KIND=8), DIMENSION(1:NX,1:NY,1:NZ), INTENT(OUT) :: u,uold
    INTEGER(kind=4) :: i,j,k

    !$OMP PARALLEL DO PRIVATE(i,j,k) SCHEDULE(static)
    DO k=1,Nz
        DO j=1,Ny
            DO i=1,Nx
                u(i,j,k)=0.5d0*exp(-1.0d0*(x(i)**2 +y(j)**2+z(k)**2))
                uold(i,j,k)=u(i,j,k)
            END DO
        END DO
    END DO
    !$OMP END PARALLEL DO

    END SUBROUTINE initialdata

END PROGRAM TestInitialData