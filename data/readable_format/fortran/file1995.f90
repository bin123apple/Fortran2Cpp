PROGRAM TestKindType
    IMPLICIT NONE
    
    ! Constants directly defined in the program
    INTEGER, PARAMETER :: ip = 4
    INTEGER, PARAMETER :: rp = 8
    INTEGER, PARAMETER :: s_name = 250
    INTEGER, PARAMETER :: s_file = 250
    INTEGER, PARAMETER :: s_mess = 100

    ! Test cases
    CALL TestConstants()

CONTAINS

    SUBROUTINE TestConstants()
        PRINT *, "Testing constants..."
        IF (ip == 4) THEN
            PRINT *, "Test ip PASS"
        ELSE
            PRINT *, "Test ip FAIL"
        END IF

        IF (rp == 8) THEN
            PRINT *, "Test rp PASS"
        ELSE
            PRINT *, "Test rp FAIL"
        END IF
        
        IF (s_name == 250) THEN
            PRINT *, "Test s_name PASS"
        ELSE
            PRINT *, "Test s_name FAIL"
        END IF

        IF (s_file == 250) THEN
            PRINT *, "Test s_file PASS"
        ELSE
            PRINT *, "Test s_file FAIL"
        END IF
        
        IF (s_mess == 100) THEN
            PRINT *, "Test s_mess PASS"
        ELSE
            PRINT *, "Test s_mess FAIL"
        END IF
    END SUBROUTINE TestConstants

END PROGRAM TestKindType