PROGRAM test_tab_data
  IMPLICIT NONE

  CHARACTER(80) :: TAB_ERRMSG(0:5)
  COMMON /TAB_DATA/ TAB_ERRMSG

  INTEGER :: i

  ! External procedure to load data, since DATA statement cannot be used in PROGRAM scope for common blocks in Fortran 77/90
  CALL load_tab_data

  ! Print the error messages to verify correctness
  DO i = 0, 5
     PRINT *, 'TAB_ERRMSG(', i, '): ', TRIM(TAB_ERRMSG(i))
  END DO

END PROGRAM test_tab_data

SUBROUTINE load_tab_data
  CHARACTER(80) :: TAB_ERRMSG(0:5)
  COMMON /TAB_DATA/ TAB_ERRMSG

  TAB_ERRMSG(0) = 'Success'
  TAB_ERRMSG(1) = 'Null tabprm pointer passed'
  TAB_ERRMSG(2) = 'Memory allocation failed'
  TAB_ERRMSG(3) = 'Invalid tabular parameters'
  TAB_ERRMSG(4) = 'One or more of the x coordinates were invalid'
  TAB_ERRMSG(5) = 'One or more of the world coordinates were invalid'

END SUBROUTINE load_tab_data