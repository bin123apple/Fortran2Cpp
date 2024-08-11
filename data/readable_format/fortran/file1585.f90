PROGRAM MainProgram
    IMPLICIT NONE

    ! Variables
    REAL :: result

    ! Main program logic
    result = DoSomething(5.0)
    PRINT *, "Result of DoSomething(5.0): ", result

CONTAINS

    ! Function definition
    FUNCTION DoSomething(x) RESULT(y)
        REAL, INTENT(IN) :: x
        REAL :: y

        ! Hypothetical functionality
        y = x * 2.0
    END FUNCTION DoSomething

END PROGRAM MainProgram