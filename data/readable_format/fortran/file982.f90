MODULE MyModule
    IMPLICIT NONE
    COMPLEX, PARAMETER :: C1 = (-3.4, 0.0)
    COMPLEX, PARAMETER :: C2 = (-3, 0.0)

    REAL, PARAMETER :: F1 = -3
    REAL, PARAMETER :: F2 = -3.4
END MODULE MyModule

PROGRAM TestMyModule
    USE MyModule
    IMPLICIT NONE
    
    PRINT *, "Testing..."
    CALL TestConstants()

CONTAINS

    SUBROUTINE TestConstants()
        IF (C1 == COMPLEX(-3.4, 0.0)) THEN
            PRINT *, "Test C1 Passed"
        ELSE
            PRINT *, "Test C1 Failed"
        END IF

        IF (C2 == COMPLEX(-3, 0.0)) THEN
            PRINT *, "Test C2 Passed"
        ELSE
            PRINT *, "Test C2 Failed"
        END IF

        IF (F1 == -3) THEN
            PRINT *, "Test F1 Passed"
        ELSE
            PRINT *, "Test F1 Failed"
        END IF

        IF (F2 == -3.4) THEN
            PRINT *, "Test F2 Passed"
        ELSE
            PRINT *, "Test F2 Failed"
        END IF
    END SUBROUTINE TestConstants

END PROGRAM TestMyModule