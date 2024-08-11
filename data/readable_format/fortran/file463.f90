MODULE FooOperations
    IMPLICIT NONE
    TYPE :: MyInt
        INTEGER :: value
    END TYPE MyInt

CONTAINS
    FUNCTION F(A, B) RESULT(res)
        TYPE(MyInt), INTENT(IN) :: A, B
        TYPE(MyInt) :: res
        res%value = A%value + B%value  ! Example operation
    END FUNCTION F
END MODULE FooOperations

PROGRAM TestFooOperator
    USE FooOperations
    IMPLICIT NONE
    INTERFACE OPERATOR(.FOO.)
        MODULE PROCEDURE F
    END INTERFACE

    TYPE(MyInt) :: A, B, C

    ! Test 1
    A%value = 5
    B%value = 3
    C = A .FOO. B
    PRINT *, "Test 1 (A=5, B=3): C = ", C%value  ! Expected Output: C = 8

    ! Test 2
    A%value = -1
    B%value = 1
    C = A .FOO. B
    PRINT *, "Test 2 (A=-1, B=1): C = ", C%value  ! Expected Output: C = 0

    ! Test 3
    A%value = 0
    B%value = 0
    C = A .FOO. B
    PRINT *, "Test 3 (A=0, B=0): C = ", C%value  ! Expected Output: C = 0
END PROGRAM TestFooOperator