PROGRAM P_TEST
    IMPLICIT NONE

    INTEGER, PARAMETER :: X(3) = 5
    INTEGER :: Y
    CHARACTER(LEN=3) :: expected_output

    ! Test case 1: X(1) = 5, expecting "BYE"
    Y = X(1)
    expected_output = "BYE"
    CALL test_case(Y, expected_output)

    ! Test case 2: Modify this to test other values if needed
    ! Y = 1
    ! expected_output = "HI"
    ! CALL test_case(Y, expected_output)

END PROGRAM P_TEST

SUBROUTINE test_case(value, expected_output)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: value
    CHARACTER(LEN=*), INTENT(IN) :: expected_output
    CHARACTER(LEN=3) :: actual_output

    SELECT CASE (value)
        CASE (1)
            actual_output = "HI"
        CASE DEFAULT
            actual_output = "BYE"
    END SELECT

    IF (actual_output == expected_output) THEN
        PRINT *, "Test Passed"
    ELSE
        PRINT *, "Test Failed: Expected: ", expected_output, " Got: ", actual_output
    END IF
END SUBROUTINE test_case