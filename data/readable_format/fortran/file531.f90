MODULE TMod
    INTEGER :: A
CONTAINS
    SUBROUTINE A22_5S_WRONG()
        PRINT *, 'A22_5S_WRONG called successfully.'
    END SUBROUTINE A22_5S_WRONG
END MODULE TMod

SUBROUTINE A22_5_WRONG()
    USE TMod
    COMMON /T/ A
    CALL A22_5S_WRONG
    A = 5
    PRINT *, 'A22_5_WRONG completed. A = ', A
END SUBROUTINE A22_5_WRONG

PROGRAM main
    CALL A22_5_WRONG
    PRINT *, 'Fortran test passed: A22_5_WRONG called successfully.'
END PROGRAM main