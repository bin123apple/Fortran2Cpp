PROGRAM Main
    IMPLICIT NONE

    ! Declarations
    INTEGER :: i

    ! Main program logic
    PRINT *, 'Hello, World!'

    ! Call a subroutine
    CALL SubroutineExample

    ! Call a function
    i = FunctionExample(5)
    PRINT *, 'FunctionExample returned: ', i

CONTAINS

    SUBROUTINE SubroutineExample
        PRINT *, 'This is a subroutine.'
    END SUBROUTINE SubroutineExample

    FUNCTION FunctionExample(n) RESULT(res)
        IMPLICIT NONE
        INTEGER, INTENT(IN) :: n
        INTEGER :: res

        res = n * 2
    END FUNCTION FunctionExample

END PROGRAM Main