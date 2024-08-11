PROGRAM main
  IMPLICIT NONE

  TYPE :: the_distribution
    INTEGER :: parameters(2)
  END TYPE the_distribution

  TYPE(the_distribution), PARAMETER :: the_beta = the_distribution((/99,999/))

  CALL cdf_beta(1, 99)
  CALL cdf_beta(2, 999)

CONTAINS

  SUBROUTINE set_bound(arg_name, test)
    INTEGER, INTENT(IN) :: arg_name, test
    IF (arg_name .NE. test) THEN
      PRINT *, 'Error in set_bound: Argument does not match test value.'
      STOP
    END IF
  END SUBROUTINE set_bound

  SUBROUTINE cdf_beta(which, test)
    INTEGER :: which, test
    CALL set_bound(the_beta%parameters(which), test)
  END SUBROUTINE cdf_beta

END PROGRAM main