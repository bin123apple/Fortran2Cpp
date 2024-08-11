MODULE SquareMod
    IMPLICIT NONE
CONTAINS
    ! This function returns the square of a number
    FUNCTION square(x) RESULT(res)
        INTEGER, INTENT(IN) :: x
        INTEGER :: res

        res = x * x
    END FUNCTION square
END MODULE SquareMod

PROGRAM Main
    USE SquareMod
    IMPLICIT NONE
    INTEGER :: inputNumber, result

    ! Example input
    inputNumber = 5

    ! Calling the square function
    result = square(inputNumber)

    ! Print the result
    PRINT *, "The square of ", inputNumber, " is ", result
END PROGRAM Main