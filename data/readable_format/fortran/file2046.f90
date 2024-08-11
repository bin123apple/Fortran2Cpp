PROGRAM main
    IMPLICIT NONE
    CALL sub(10)
CONTAINS
    SUBROUTINE sub(a)
        INTEGER, INTENT(IN) :: a
        PRINT *, "Fortran: The value of a is", a
    END SUBROUTINE sub
END PROGRAM main