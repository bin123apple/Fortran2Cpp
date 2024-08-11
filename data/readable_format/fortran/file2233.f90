MODULE dropdep_var
    IMPLICIT NONE
    PRIVATE
    PUBLIC :: r, chr1, pi
    INTEGER, PARAMETER :: pi = 5
    INTEGER, PARAMETER :: dp = KIND(1.D0)
    REAL(KIND=dp) :: r
    CHARACTER(LEN=pi) :: chr1
END MODULE dropdep_var

PROGRAM test_dropdep_var
    USE dropdep_var
    IMPLICIT NONE
    
    ! Assign values to the variables
    r = 3.14
    chr1 = 'abcde'
    
    ! Output the variables to verify the assignment
    PRINT *, 'r = ', r
    PRINT *, 'chr1 = ', chr1
    
    ! Check the length of chr1
    IF (LEN(chr1) /= pi) THEN
        PRINT *, 'Test Failed: Length of chr1 is not equal to pi'
    ELSE
        PRINT *, 'Test Passed: Length of chr1 is equal to pi'
    END IF
END PROGRAM test_dropdep_var