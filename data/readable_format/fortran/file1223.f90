MODULE code_mod
    IMPLICIT NONE
CONTAINS
    FUNCTION check_conditions(K, J) RESULT(res)
        INTEGER, INTENT(IN) :: K(3), J(3)
        INTEGER :: res

        IF (ANY(MAXLOC(K, J<3) .NE. 1)) THEN
            res = 1
        ELSE IF (ANY(J .NE. 2)) THEN
            res = 2
        ELSE
            res = 0
        END IF
    END FUNCTION check_conditions
END MODULE code_mod

PROGRAM main
    USE code_mod
    INTEGER :: K(3) = 1, J(3) = 2, res

    res = check_conditions(K, J)
    PRINT *, "Result:", res
END PROGRAM main