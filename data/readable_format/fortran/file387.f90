PROGRAM test_kind_params
  IMPLICIT NONE
  INTEGER, PARAMETER :: wp = SELECTED_REAL_KIND(12, 307)
  REAL(wp) :: precision_test
  REAL(wp) :: range_test_min, range_test_max

  ! Test for precision
  precision_test = 1.0_wp
  precision_test = precision_test / 3.0_wp
  precision_test = precision_test * 3.0_wp
  IF (ABS(precision_test - 1.0_wp) > 1.0E-12_wp) THEN
    PRINT *, "Precision test failed."
  ELSE
    PRINT *, "Precision test passed."
  END IF

  ! Test for range
  range_test_min = 10.0_wp**(-307)
  range_test_max = 10.0_wp**307
  IF (range_test_min > 0.0_wp .AND. range_test_max > 0.0_wp) THEN
    PRINT *, "Range test passed."
  ELSE
    PRINT *, "Range test failed."
  END IF
END PROGRAM test_kind_params