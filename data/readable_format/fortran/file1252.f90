SUBROUTINE DLASCL2(M, N, D, X, LDX)
    INTEGER            M, N, LDX
    DOUBLE PRECISION   D(*), X(LDX, *)
    INTEGER            I, J
    
    DO J = 1, N
        DO I = 1, M
            X(I, J) = X(I, J) * D(I)
        END DO
    END DO
    
    RETURN
END SUBROUTINE DLASCL2

PROGRAM testDLASCL2
    IMPLICIT NONE
    INTEGER, PARAMETER :: M = 3, N = 2
    DOUBLE PRECISION, DIMENSION(M) :: D
    DOUBLE PRECISION, DIMENSION(M, N) :: X
    INTEGER :: i, j
    
    ! Initialize D and X
    D = (/1.0, 2.0, 3.0/)
    DO i = 1, M
        DO j = 1, N
            X(i, j) = i * j
        END DO
    END DO
    
    ! Call the subroutine
    CALL DLASCL2(M, N, D, X, M)
    
    ! Print the scaled matrix
    DO i = 1, M
        DO j = 1, N
            PRINT *, 'X(', i, ',', j, ') = ', X(i, j)
        END DO
    END DO
END PROGRAM testDLASCL2