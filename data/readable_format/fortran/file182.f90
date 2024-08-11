PROGRAM MAIN
    IMPLICIT NONE
    REAL :: result

    result = ANINT(1.2)
    IF (result .EQ. 1.0) THEN
        PRINT *, "ANINT Test Passed"
    ELSE
        PRINT *, "ANINT Test Failed"
    END IF

    result = AINT(1.2)
    IF (result .EQ. 1.0) THEN
        PRINT *, "AINT Test Passed"
    ELSE
        PRINT *, "AINT Test Failed"
    END IF

    result = ATAN(ANINT(1.2))
    IF (result .EQ. ATAN(1.0)) THEN
        PRINT *, "ATAN(ANINT) Test Passed"
    ELSE
        PRINT *, "ATAN(ANINT) Test Failed"
    END IF

    result = ATAN(AINT(1.2))
    IF (result .EQ. ATAN(1.0)) THEN
        PRINT *, "ATAN(AINT) Test Passed"
    ELSE
        PRINT *, "ATAN(AINT) Test Failed"
    END IF
END PROGRAM MAIN