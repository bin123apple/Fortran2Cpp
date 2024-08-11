MODULE plugin_flags
  ! Any necessary declarations go here
END MODULE plugin_flags

SUBROUTINE plugin_clean( prog, lflag )
  USE plugin_flags
  IMPLICIT NONE
  CHARACTER(LEN=*), INTENT(IN) :: prog
  LOGICAL, INTENT(IN) :: lflag
  ! For test purposes, we'll print the inputs
  PRINT *, 'Program:', prog
  PRINT *, 'Flag:', lflag
END SUBROUTINE plugin_clean

PROGRAM test_plugin_clean
  USE plugin_flags
  IMPLICIT NONE
  CALL plugin_clean('TestProgram', .TRUE.)
  CALL plugin_clean('AnotherTest', .FALSE.)
END PROGRAM test_plugin_clean