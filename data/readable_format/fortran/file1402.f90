PROGRAM testSB02MR
  IMPLICIT NONE
  DOUBLE PRECISION :: reigTest
  LOGICAL :: result
  
  reigTest = 1.0D0
  result = SB02MR(reigTest, 0.0D0)
  CALL ASSERT(result, "Test with positive REIG failed.")
  
  reigTest = 0.0D0
  result = SB02MR(reigTest, 0.0D0)
  CALL ASSERT(result, "Test with zero REIG failed.")
  
  reigTest = -1.0D0
  result = SB02MR(reigTest, 0.0D0)
  CALL ASSERT(.NOT. result, "Test with negative REIG failed.")

CONTAINS

  LOGICAL FUNCTION SB02MR(REIG, IEIG)
    DOUBLE PRECISION, INTENT(IN) :: REIG, IEIG
    DOUBLE PRECISION :: ZERO
    PARAMETER (ZERO = 0.0D0)
    SB02MR = REIG >= ZERO
  END FUNCTION SB02MR

  SUBROUTINE ASSERT(condition, message)
    LOGICAL, INTENT(IN) :: condition
    CHARACTER(*), INTENT(IN) :: message
    IF (.NOT. condition) THEN
      PRINT *, "Assertion failed:", message
    ELSE
      PRINT *, "Test passed."
    END IF
  END SUBROUTINE ASSERT

END PROGRAM testSB02MR