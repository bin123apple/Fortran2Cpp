! myModule.f90
MODULE myModule
    IMPLICIT NONE
CONTAINS
    FUNCTION square(x) RESULT(result)
        INTEGER, INTENT(IN) :: x
        INTEGER :: result
        result = x * x
    END FUNCTION square

    FUNCTION increment(x) RESULT(result)
        INTEGER, INTENT(IN) :: x
        INTEGER :: result
        result = x + 10
    END FUNCTION increment
END MODULE myModule

PROGRAM testMyModule
    USE myModule
    IMPLICIT NONE
    INTEGER :: squared, incremented

    ! Unit test for square function
    PRINT *, 'Testing square function...'
    squared = square(4)
    PRINT *, 'Square of 4:', squared

    ! Unit test for increment function
    PRINT *, 'Testing increment function...'
    incremented = increment(5)
    PRINT *, 'Increment of 5 by 10:', incremented
END PROGRAM testMyModule