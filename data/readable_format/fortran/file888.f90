MODULE kinds
  IMPLICIT NONE
  INTEGER, PARAMETER :: DP = SELECTED_REAL_KIND(15, 307)
END MODULE kinds

MODULE parameters
  USE kinds
  IMPLICIT NONE
  ! Example parameter, if needed
  REAL(DP) :: example_parameter = 1.0_DP
END MODULE parameters

MODULE plugin_variables
  USE kinds
  USE parameters
  IMPLICIT NONE
  SAVE
  PRIVATE
  PUBLIC :: plugin_etot
  REAL(DP) :: plugin_etot
END MODULE plugin_variables

PROGRAM test_plugin_variables
  USE kinds
  USE plugin_variables
  IMPLICIT NONE

  ! Test initialization
  plugin_etot = 0.0_DP
  IF (ABS(plugin_etot) > 1.0E-10_DP) THEN
    PRINT *, "Test failed: Initial value of plugin_etot is not 0.0"
  ELSE
    PRINT *, "Test passed: Initial value of plugin_etot is 0.0"
  END IF

  ! Test setting and getting
  plugin_etot = 5.0_DP
  IF (ABS(plugin_etot - 5.0_DP) > 1.0E-10_DP) THEN
    PRINT *, "Test failed: Setting or getting plugin_etot did not work as expected"
  ELSE
    PRINT *, "Test passed: Setting and getting plugin_etot works as expected"
  END IF

END PROGRAM test_plugin_variables