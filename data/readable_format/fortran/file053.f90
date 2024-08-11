PROGRAM P
IMPLICIT NONE
INTEGER :: I, J, K
K = 0

DO I = 1, 100
    K = K + 1
    DO J = 1, 100
        EXIT
    END DO
END DO

PRINT *, "Count:", K
END PROGRAM P