PROGRAM TEST_IZERO
  IMPLICIT NONE
  INTEGER :: i, errors
  INTEGER, ALLOCATABLE :: test_array(:)

  errors = 0

  ! Test 1: Test with array of length 5
  ALLOCATE(test_array(5))
  test_array = (/1, 2, 3, 4, 5/)
  CALL IZERO(test_array, 5)
  DO i = 1, SIZE(test_array)
    IF (test_array(i) /= 0) THEN
      PRINT *, "Test 1 failed at index ", i
      errors = errors + 1
    END IF
  END DO
  DEALLOCATE(test_array)

  ! Test 2: Test with an empty array
  ALLOCATE(test_array(0))
  CALL IZERO(test_array, 0)
  IF (SIZE(test_array) /= 0) THEN
    PRINT *, "Test 2 failed."
    errors = errors + 1
  END IF
  DEALLOCATE(test_array)

  ! Final report
  IF (errors == 0) THEN
    PRINT *, "All tests passed."
  ELSE
    PRINT *, errors, " tests failed."
  END IF

END PROGRAM TEST_IZERO

SUBROUTINE IZERO(IVEC, LEN)
  INTEGER, INTENT(INOUT) :: IVEC(*)
  INTEGER, INTENT(IN) :: LEN
  INTEGER :: I
  IF (LEN < 1) RETURN
  DO I = 1, LEN
     IVEC(I) = 0
  END DO
  RETURN
END SUBROUTINE IZERO