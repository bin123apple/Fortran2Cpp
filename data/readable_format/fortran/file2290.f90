PROGRAM main
  IMPLICIT NONE

  INTEGER :: a(3), f, i
  INTEGER, PARAMETER :: expected_value = 42
  LOGICAL :: test_passed

  a = f()

  test_passed = .TRUE.
  DO i = 1, SIZE(a)
    IF (a(i) /= expected_value) THEN
      test_passed = .FALSE.
      EXIT
    END IF
  END DO

  IF (test_passed) THEN
    PRINT *, 'Test Passed'
  ELSE
    PRINT *, 'Test Failed'
  END IF

END PROGRAM main

INTEGER FUNCTION f()
  f = 42
END FUNCTION f