PROGRAM test_iau_ANP
  IMPLICIT NONE
  
  ! Test cases and their expected results
  DOUBLE PRECISION, PARAMETER :: test_cases(3) = (/ -1.0D0, 0.0D0, 7.0D0 /)
  DOUBLE PRECISION, PARAMETER :: expected_results(3) = (/ 5.283185307179586D0, 0.0D0, 0.7168146928204138D0 /)
  DOUBLE PRECISION :: result
  INTEGER :: i
  
  DO i = 1, SIZE(test_cases)
    result = iau_ANP(test_cases(i))
    PRINT *, 'Test case: ', test_cases(i), ' Result: ', result, ' Expected: ', expected_results(i)
    IF (ABS(result - expected_results(i)) > 1.0D-10) THEN
      PRINT *, 'Test failed!'
    ELSE
      PRINT *, 'Test passed!'
    END IF
  END DO

CONTAINS

  DOUBLE PRECISION FUNCTION iau_ANP(A)
    IMPLICIT NONE
    DOUBLE PRECISION, INTENT(IN) :: A
    DOUBLE PRECISION :: D2PI
    PARAMETER (D2PI = 6.283185307179586476925287D0)
    DOUBLE PRECISION :: W

    W = MOD(A, D2PI)
    IF (W < 0D0) W = W + D2PI
    iau_ANP = W
  END FUNCTION iau_ANP

END PROGRAM test_iau_ANP