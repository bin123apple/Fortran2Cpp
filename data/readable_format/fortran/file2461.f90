MODULE vast_kind_param
    INTEGER, PARAMETER :: DOUBLE = SELECTED_REAL_KIND(15, 307)
END MODULE vast_kind_param

MODULE etrbk3_I
    INTERFACE
        SUBROUTINE etrbk3 (NM, N, NV, A, M, Z) 
            USE vast_kind_param, ONLY: DOUBLE 
            integer, INTENT(IN) :: NM 
            integer, INTENT(IN) :: N 
            integer, INTENT(IN) :: NV 
            real(DOUBLE), DIMENSION(NV), INTENT(IN) :: A 
            integer, INTENT(IN) :: M 
            real(DOUBLE), DIMENSION(NM,M) :: Z 
        END SUBROUTINE  
    END INTERFACE 
END MODULE

SUBROUTINE etrbk3 (NM, N, NV, A, M, Z)
    USE vast_kind_param, ONLY: DOUBLE
    INTEGER, INTENT(IN) :: NM 
    INTEGER, INTENT(IN) :: N 
    INTEGER, INTENT(IN) :: NV 
    REAL(DOUBLE), DIMENSION(NV), INTENT(IN) :: A 
    INTEGER, INTENT(IN) :: M 
    REAL(DOUBLE), DIMENSION(NM,M) :: Z 

    INTEGER :: I

    ! Simple example: Copy A into the first row of Z
    IF (NV <= M) THEN
        DO I = 1, NV
            Z(1, I) = A(I)
        END DO
    END IF
END SUBROUTINE

PROGRAM test_etrbk3
    USE vast_kind_param
    USE etrbk3_I
    IMPLICIT NONE

    INTEGER :: NM, N, NV, M
    REAL(DOUBLE), DIMENSION(:), ALLOCATABLE :: A
    REAL(DOUBLE), DIMENSION(:,:), ALLOCATABLE :: Z
    INTEGER :: I

    ! Set test parameters
    NM = 2
    N = 3
    NV = 3
    M = 3

    ! Allocate and initialize arrays
    ALLOCATE(A(NV))
    ALLOCATE(Z(NM, M))

    A = (/ 1.0_DOUBLE, 2.0_DOUBLE, 3.0_DOUBLE /)
    Z = 0.0_DOUBLE

    ! Call the subroutine
    CALL etrbk3(NM, N, NV, A, M, Z)

    ! Print the result for verification
    PRINT *, 'Z:'
    DO I = 1, NM
        PRINT *, Z(I, :)
    END DO

    ! Deallocate arrays
    DEALLOCATE(A)
    DEALLOCATE(Z)
END PROGRAM