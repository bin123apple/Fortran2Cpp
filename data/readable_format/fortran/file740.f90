PROGRAM ConditionalTest
    IMPLICIT NONE
    INTEGER :: nerr, i

    DO i = 1, 4
        IF (i == 1) THEN
            nerr = 0  ! Simulating no error condition for the first process
        ELSE
            nerr = 1  ! Simulating an error condition for other processes
        END IF

        ! Conditional printing based on the simulated error condition
        IF (nerr == 0) THEN
            PRINT *, 'Process', i, ': OK'
        ELSE
            PRINT *, 'Process', i, ': Error detected'
        END IF
    END DO
END PROGRAM ConditionalTest