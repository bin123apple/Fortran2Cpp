PROGRAM test_real8
  IMPLICIT NONE
  INTEGER, PARAMETER :: REAL_8 = 8
  REAL(REAL_8) :: num

  num = 1_REAL_8
  PRINT *, "Testing 1_REAL_8..."
  PRINT *, "Expected: 1.0 (or close to 1.0 depending on precision)"
  PRINT *, "Got: ", num

END PROGRAM test_real8