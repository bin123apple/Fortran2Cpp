MODULE M1
    INTEGER, PARAMETER :: N = 10
END MODULE M1

SUBROUTINE transposeMatrix(V)
    USE M1, ONLY: N
    IMPLICIT NONE
    INTEGER, INTENT(INOUT) :: V(N, N)
    INTEGER :: i, j, temp

    DO i = 1, N
        DO j = i+1, N
            temp = V(i, j)
            V(i, j) = V(j, i)
            V(j, i) = temp
        END DO
    END DO
END SUBROUTINE transposeMatrix

PROGRAM TestTranspose
    USE M1, ONLY: N
    IMPLICIT NONE
    INTEGER :: A(N, N), i, j
    LOGICAL :: testPassed

    ! Initialize the matrix A
    DO i = 1, N
        DO j = 1, N
            A(i, j) = i * 10 + j
        END DO
    END DO

    CALL transposeMatrix(A)

    ! Check the result
    testPassed = .TRUE.
    DO i = 1, N
        DO j = 1, N
            IF (A(i, j) /= j * 10 + i) THEN
                testPassed = .FALSE.
                EXIT
            END IF
        END DO
        IF (.NOT. testPassed) EXIT
    END DO

    IF (testPassed) THEN
        PRINT *, "Test passed."
    ELSE
        PRINT *, "Test failed."
    END IF
END PROGRAM TestTranspose