SUBROUTINE GIARGS(UNIT, ARGS, STATUS)
      INTEGER UNIT, STATUS
      CHARACTER*(*) ARGS
      STATUS = 1
      RETURN
      END

      PROGRAM testGIARGS
      INTEGER UNIT, STATUS
      CHARACTER*100 ARGS

      UNIT = 5
      ARGS = 'Test String'
      STATUS = 0

      CALL GIARGS(UNIT, ARGS, STATUS)

      IF (STATUS .EQ. 1) THEN
        PRINT *, 'Test Passed: STATUS is 1'
      ELSE
        PRINT *, 'Test Failed: STATUS is not 1'
      END IF
      END PROGRAM testGIARGS