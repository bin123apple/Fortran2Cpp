MODULE m
  IMPLICIT NONE

  TYPE t
  CONTAINS
    PROCEDURE, NOPASS, PRIVATE :: priv => proc
    PROCEDURE, NOPASS, PUBLIC :: publ => proc
  END TYPE t

CONTAINS

  SUBROUTINE proc ()
    PRINT *, "Procedure called"
  END SUBROUTINE proc

END MODULE m

PROGRAM test
  USE m
  IMPLICIT NONE
  TYPE(t) :: obj

  ! This will work
  CALL obj%publ ()

  ! This would fail if attempted outside the module 'm', but we cannot
  ! demonstrate it here since Fortran does not allow calling private
  ! module procedures from outside the module itself.
END PROGRAM test