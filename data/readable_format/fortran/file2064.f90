! Modified subroutine with print statements for demonstration
SUBROUTINE S(X, Y)
    IMPLICIT NONE
    INTEGER :: X
    REAL :: Y
    PRINT *, 'X = ', X, 'Y = ', Y
END SUBROUTINE S

PROGRAM P
    IMPLICIT NONE
    CALL S(1, 2.0)
    CALL S(1, 2.2)
END PROGRAM P