PROGRAM test_prog

    IMPLICIT NONE

    TYPE ProcPointerType
        PROCEDURE(triple), POINTER, NOPASS :: f
    END TYPE ProcPointerType

    TYPE (ProcPointerType) :: ppt
    REAL :: tres(2)
    REAL :: expected(2)
    INTEGER :: i

    ppt%f => triple

    ! Test 1
    tres = ppt%f(2, [2., 4.])
    expected = [6., 12.]
    DO i = 1, 2
        IF (ABS(tres(i) - expected(i)) > 1E-3) THEN
            PRINT *, "Test 1 Failed at index:", i
            STOP
        END IF
    END DO
    PRINT *, "Test 1 Passed"

    ! Test 2
    tres = ppt%f(2, [3., 5.])
    expected = [9., 15.]
    DO i = 1, 2
        IF (ABS(tres(i) - expected(i)) > 1E-3) THEN
            PRINT *, "Test 2 Failed at index:", i
            STOP
        END IF
    END DO
    PRINT *, "Test 2 Passed"

CONTAINS

    FUNCTION triple(n, x) RESULT(tre)
        INTEGER, INTENT(IN) :: n
        REAL, INTENT(IN) :: x(2)
        REAL :: tre(2)
        tre = 3. * x
    END FUNCTION triple

END PROGRAM test_prog