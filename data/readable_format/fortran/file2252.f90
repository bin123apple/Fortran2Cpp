PROGRAM test_sla_DVN
    IMPLICIT NONE

    DOUBLE PRECISION V(3), UV(3), VM
    INTEGER I

    ! Test case 1
    V(1) = 1.0D0
    V(2) = 0.0D0
    V(3) = 0.0D0

    CALL sla_DVN(V, UV, VM)

    PRINT *, 'Test Case 1:'
    PRINT *, 'Input Vector: ', V
    PRINT *, 'Unit Vector: ', UV
    PRINT *, 'Magnitude: ', VM

    ! Test case 2
    V(1) = 3.0D0
    V(2) = 4.0D0
    V(3) = 0.0D0

    CALL sla_DVN(V, UV, VM)

    PRINT *, 'Test Case 2:'
    PRINT *, 'Input Vector: ', V
    PRINT *, 'Unit Vector: ', UV
    PRINT *, 'Magnitude: ', VM

END PROGRAM test_sla_DVN

SUBROUTINE sla_DVN (V, UV, VM)
    IMPLICIT NONE

    DOUBLE PRECISION V(3), UV(3), VM
    INTEGER I
    DOUBLE PRECISION W1, W2

    W1 = 0D0
    DO I = 1, 3
        W2 = V(I)
        W1 = W1 + W2 * W2
    END DO
    W1 = SQRT(W1)
    VM = W1

    IF (W1 .LE. 0D0) W1 = 1D0
    DO I = 1, 3
        UV(I) = V(I) / W1
    END DO
END SUBROUTINE sla_DVN