MODULE m
  IMPLICIT NONE
CONTAINS
  SUBROUTINE s
    CALL upper
    CALL lower
  END SUBROUTINE s

  SUBROUTINE upper
    REAL :: y
    y = x(3,1)
    IF (INT(y) /= 3) CALL abort_program
  END SUBROUTINE upper

  FUNCTION x(n, m)
    REAL :: x
    INTEGER, INTENT(IN) :: n, m
    x = m * n
  END FUNCTION x

  SUBROUTINE lower
    REAL :: y
    y = x(2,1)
    IF (INT(y) /= 2) CALL abort_program
  END SUBROUTINE lower

  SUBROUTINE abort_program
    PRINT *, "Test failed."
    STOP
  END SUBROUTINE abort_program
END MODULE m

PROGRAM test
  USE m
  CALL s
  PRINT *, "All tests passed."
END PROGRAM test