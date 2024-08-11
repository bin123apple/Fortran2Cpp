PROGRAM test
      GOTO 3
 2    CONTINUE
      PRINT *, 'This line should not execute'
      STOP
 3    CONTINUE
      PRINT *, 'Label 3 reached'
      END PROGRAM test