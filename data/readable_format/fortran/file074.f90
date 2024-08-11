PROGRAM P
    IMPLICIT NONE
    TYPE T
        INTEGER :: X
        INTEGER :: Y
    END TYPE T

    TYPE(T) :: S

    S % X = 1
    S % Y = 2
    
    ! Test the initial values of S
    IF (S % X == 1 .AND. S % Y == 2) THEN
        PRINT *, "Test 1 Passed: S%X=1, S%Y=2"
    ELSE
        PRINT *, "Test 1 Failed"
    END IF

    BLOCK
        TYPE T
            INTEGER :: X
            INTEGER :: Y
        END TYPE T

        TYPE(T) :: S

        S % X = 3
        S % Y = 4
    END BLOCK

    BLOCK
        TYPE T
            INTEGER :: X
            INTEGER :: Y
        END TYPE T

        TYPE(T) :: S

        S % X = 5
        S % Y = 6
    END BLOCK

    ! At this point, S should still have its original values due to block scoping
    IF (S % X == 1 .AND. S % Y == 2) THEN
        PRINT *, "Test 2 Passed: Outer S values unchanged by BLOCKs"
    ELSE
        PRINT *, "Test 2 Failed"
    END IF

    ! The original conditional check seems logically flawed as it would always be true
    ! Demonstrating a simple correction for educational purposes
    IF (S % X /= 1 .AND. S % X /= 2) THEN
        PRINT *, "Unexpected values for S%X"
    ELSE
        PRINT *, "S%X has expected value"
    END IF
END PROGRAM P