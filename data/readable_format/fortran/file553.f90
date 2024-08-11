PROGRAM TestLoop15
    IMPLICIT NONE
    INTEGER, PARAMETER :: N = 5
    DOUBLE PRECISION :: x(N), a(N), b(N), c(N)
    INTEGER :: i
    
    ! Initialize arrays
    DO i = 1, N
        a(i) = REAL(i)
        b(i) = 2.0D0 * REAL(i)
        c(i) = REAL(i) + 0.5D0
    END DO
    
    ! Call the subroutine
    CALL loop15_F90(N, x, a, b, c)
    
    ! Output results for verification
    PRINT *, 'Results for loop15_F90:'
    DO i = 1, N
        PRINT *, 'x(', i, ') = ', x(i)
    END DO
    
CONTAINS

    SUBROUTINE loop15_F90(N, x, a, b, c)
        INTEGER, INTENT(IN) :: N
        DOUBLE PRECISION, INTENT(IN) :: a(N), b(N), c(N)
        DOUBLE PRECISION, INTENT(OUT) :: x(N)
        INTEGER :: i
        
        ! Perform the operation
        DO i = 1, N
            x(i) = c(i) + a(i) * b(i)
        END DO
    END SUBROUTINE loop15_F90

    SUBROUTINE loop15_F90Overhead(N, x, a, b, c)
        INTEGER, INTENT(IN) :: N
        DOUBLE PRECISION, INTENT(IN) :: a(N), b(N), c(N)
        DOUBLE PRECISION, INTENT(OUT) :: x(N)
        ! This subroutine intentionally left blank
    END SUBROUTINE loop15_F90Overhead

END PROGRAM TestLoop15