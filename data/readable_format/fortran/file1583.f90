SUBROUTINE QUICK
      SAVE
      ASSIGN 101 TO JUMP
  101 CONTINUE
      RETURN
      END

      PROGRAM testQuick
      CALL QUICK
      PRINT *, 'Test Passed.'
      END PROGRAM testQuick