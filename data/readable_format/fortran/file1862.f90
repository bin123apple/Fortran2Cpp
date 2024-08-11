PROGRAM testMain
    IMPLICIT NONE
    CALL testSubmatrixAssignment()
    PRINT *, "All tests passed."
END PROGRAM testMain

SUBROUTINE testSubmatrixAssignment()
    INTEGER, TARGET :: A(1:5, 1:5)
    INTEGER, POINTER :: PA(:, :)
    INTEGER :: I, J
    LOGICAL :: testPassed

    ! Test 1: Submatrix assignment
    A = 1
    PA(1:,1:) => A(2:4, 2:4)
    PA = 2
    testPassed = .TRUE.
    DO I = 1, 5
        DO J = 1, 5
            IF (2 <= I .AND. I <= 4 .AND. 2 <= J .AND. J <= 4) THEN
                IF (A(I, J) /= 2) THEN
                    testPassed = .FALSE.
                    EXIT
                END IF
            ELSE
                IF (A(I, J) /= 1) THEN
                    testPassed = .FALSE.
                    EXIT
                END IF
            END IF
        END DO
        IF (.NOT. testPassed) EXIT
    END DO
    IF (testPassed) THEN
        PRINT *, "Test 1 passed."
    ELSE
        PRINT *, "Test 1 failed."
        STOP
    END IF
END SUBROUTINE testSubmatrixAssignment