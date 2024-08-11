PROGRAM test_me08a
    IMPLICIT NONE
    COMPLEX, DIMENSION(2,2) :: A
    COMPLEX, DIMENSION(1) :: ALPHA, BETA, Q
    INTEGER :: N, IA

    ! Initialize values
    N = 2
    IA = 2
    A = RESHAPE([ (1.0, 2.0), (3.0, 4.0), (5.0, 6.0), (7.0, 8.0) ], SHAPE(A))
    ALPHA(1) = (2.0, 0.0)
    BETA(1) = (1.0, 0.0)
    Q(1) = (0.0, 0.0)

    ! Call the subroutine
    CALL me08a(A, ALPHA, BETA, N, IA, Q)

    ! Output results for verification
    PRINT *, "A after operation: ", A
    PRINT *, "Q after operation: ", Q

CONTAINS

    SUBROUTINE me08a(A, ALPHA, BETA, N, IA, Q)
        INTEGER, INTENT(IN) :: N, IA  
        COMPLEX, DIMENSION(IA,*) :: A 
        COMPLEX, INTENT(IN) :: ALPHA(*) 
        COMPLEX, INTENT(INOUT) :: BETA(*)       
        COMPLEX, INTENT(INOUT) :: Q(*) 

        ! Example operation (this should be replaced with the actual logic)
        INTEGER :: i, j
        DO i = 1, IA
            DO j = 1, N
                A(i,j) = A(i,j) * ALPHA(1)
            END DO
        END DO
        Q(1) = Q(1) + BETA(1)

    END SUBROUTINE me08a
END PROGRAM test_me08a