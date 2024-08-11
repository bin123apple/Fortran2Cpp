MODULE ksbin1_aux_mod
  IMPLICIT NONE
CONTAINS
  FUNCTION setbd()
    INTEGER :: setbd
    setbd = 42
  END FUNCTION setbd

  SUBROUTINE foo()
    IF (setbd() .NE. 42) STOP 'Error in foo'
    PRINT *, "foo check passed"
  END SUBROUTINE foo
END MODULE ksbin1_aux_mod

PROGRAM test
  USE ksbin1_aux_mod
  CALL foo()
  PRINT *, "All Fortran tests passed"
END PROGRAM test