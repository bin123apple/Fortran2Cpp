MODULE PYTHAG_SP__genmod
  IMPLICIT NONE
CONTAINS
  ! Function to calculate the hypotenuse
  FUNCTION PYTHAG_SP(A, B)
    REAL(KIND=8), INTENT(IN) :: A, B
    REAL(KIND=8) :: PYTHAG_SP
    PYTHAG_SP = SQRT(A*A + B*B)
  END FUNCTION PYTHAG_SP
  
  ! Subroutine for testing
  SUBROUTINE TEST_PYTHAG_SP()
    REAL(KIND=8) :: result
    PRINT *, "Testing PYTHAG_SP function"
    ! Test 1: Both sides zero
    result = PYTHAG_SP(0.0D0, 0.0D0)
    IF (result .EQ. 0.0D0) THEN
      PRINT *, "Test 1 Passed."
    ELSE
      PRINT *, "Test 1 Failed."
    END IF
    
    ! Test 2: One side zero, the other positive
    result = PYTHAG_SP(0.0D0, 3.0D0)
    IF (result .EQ. 3.0D0) THEN
      PRINT *, "Test 2 Passed."
    ELSE
      PRINT *, "Test 2 Failed."
    END IF
    
    ! Test 3: Both sides positive and equal
    result = PYTHAG_SP(3.0D0, 3.0D0)
    IF (result .EQ. SQRT(18.0D0)) THEN
      PRINT *, "Test 3 Passed."
    ELSE
      PRINT *, "Test 3 Failed."
    END IF
    
    ! Test 4: Both sides positive and different
    result = PYTHAG_SP(3.0D0, 4.0D0)
    IF (result .EQ. 5.0D0) THEN
      PRINT *, "Test 4 Passed."
    ELSE
      PRINT *, "Test 4 Failed."
    END IF
  END SUBROUTINE TEST_PYTHAG_SP
END MODULE PYTHAG_SP__genmod

PROGRAM test_pythag
  USE PYTHAG_SP__genmod
  CALL TEST_PYTHAG_SP()
END PROGRAM test_pythag