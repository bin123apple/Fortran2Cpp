PROGRAM P
    IMPLICIT NONE
    INTEGER :: A
    CALL IncrementA(10)
    PRINT *, 'Test IncrementA with start value 0 and increment 10: ', A
    CALL IncrementA(-5)
    PRINT *, 'Test IncrementA with current value 10 and decrement 5: ', A
CONTAINS
    SUBROUTINE IncrementA(value)
        INTEGER, INTENT(IN) :: value
        A = A + value
    END SUBROUTINE IncrementA
END PROGRAM P