PROGRAM test_program
    IMPLICIT NONE
    CALL test_dev
END PROGRAM

SUBROUTINE test_dev
    IMPLICIT NONE
    INTEGER :: DEV = 0
    ! Normally, you would do something with DEV here
    PRINT *, "DEV is: ", DEV
    ! Here we might test DEV's value or behavior
END SUBROUTINE test_dev