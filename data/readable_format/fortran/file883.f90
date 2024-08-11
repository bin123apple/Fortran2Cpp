PROGRAM testLinErrMsg
    CHARACTER(80) LIN_ERRMSG(0:3)
    COMMON /LIN_DATA/ LIN_ERRMSG

    LIN_ERRMSG(0) = 'Success'
    LIN_ERRMSG(1) = 'Null linprm pointer passed'
    LIN_ERRMSG(2) = 'Memory allocation failed'
    LIN_ERRMSG(3) = 'PCi_ja matrix is singular'

    CALL CheckErrMsg(0, 'Success')
    CALL CheckErrMsg(1, 'Null linprm pointer passed')
    CALL CheckErrMsg(2, 'Memory allocation failed')
    CALL CheckErrMsg(3, 'PCi_ja matrix is singular')

    STOP
END PROGRAM testLinErrMsg

SUBROUTINE CheckErrMsg(index, expected)
    INTEGER index
    CHARACTER*(*) expected
    CHARACTER(80) LIN_ERRMSG(0:3)
    COMMON /LIN_DATA/ LIN_ERRMSG

    IF (LIN_ERRMSG(index) .EQ. expected) THEN
        PRINT *, 'Test passed for index:', index
    ELSE
        PRINT *, 'Test FAILED for index:', index
        PRINT *, 'Expected:', expected
        PRINT *, 'Got:', LIN_ERRMSG(index)
    END IF
END SUBROUTINE CheckErrMsg