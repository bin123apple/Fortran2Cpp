MODULE printmod
  IMPLICIT NONE
CONTAINS
  SUBROUTINE printNumber()
    PRINT *, 42
  END SUBROUTINE printNumber
END MODULE printmod

PROGRAM main
  USE printmod
  CALL printNumber()
END PROGRAM main