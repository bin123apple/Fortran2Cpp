PROGRAM MainProgram
  IMPLICIT NONE
  
  CALL TestSubroutine
  CALL TestFunction

CONTAINS

  SUBROUTINE PrintMessage()
    PRINT *, "This is a subroutine"
  END SUBROUTINE PrintMessage
  
  FUNCTION DoubleValue(x) RESULT(res)
    INTEGER, INTENT(IN) :: x
    INTEGER :: res
    res = x * 2
  END FUNCTION DoubleValue
  
  SUBROUTINE TestSubroutine
    CALL PrintMessage
  END SUBROUTINE TestSubroutine
  
  SUBROUTINE TestFunction
    INTEGER :: result
    result = DoubleValue(5)
    PRINT *, result
  END SUBROUTINE TestFunction
  
END PROGRAM MainProgram