PROGRAM Main
  CALL A6_WRONG
END PROGRAM Main

SUBROUTINE WORK(I, J)
  INTEGER I,J
  ! Potentially add some code here to see effects of WORK being called.
  PRINT *, 'WORK called with I=', I, ' and J=', J
END SUBROUTINE WORK

SUBROUTINE A6_WRONG
  INTEGER I, J
  DO 100 I = 1,10
    DO 100 J = 1,10
      CALL WORK(I,J)
  100 CONTINUE
END SUBROUTINE A6_WRONG