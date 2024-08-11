PROGRAM test
  IMPLICIT NONE

  TYPE :: basics_t
    INTEGER :: i = 42
    REAL :: r = 0.0
    COMPLEX :: c = (0., 1.)
  END TYPE basics_t

  TYPE(basics_t) :: basics

  basics = basics_t (i = 42)
  ! Test default values and initialization
  IF (basics%i /= 42) CALL report_error('i')
  IF (basics%r /= 0.0) CALL report_error('r')
  IF (REAL(basics%c) /= 0.0 .OR. AIMAG(basics%c) /= 1.0) CALL report_error('c')

  PRINT *, 'Fortran tests completed successfully.'

CONTAINS

  SUBROUTINE report_error(variable_name)
    CHARACTER(len=*), INTENT(IN) :: variable_name
    PRINT *, 'Error in', variable_name
  END SUBROUTINE report_error

END PROGRAM test