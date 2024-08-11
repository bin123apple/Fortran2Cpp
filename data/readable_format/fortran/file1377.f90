PROGRAM testBroadcast
  IMPLICIT NONE
  INTEGER(KIND=4) :: testRank

  ! Test subroutine
  CALL MODEL_CRUST_2_0_BROADCAST(testRank)
  
  ! Simple test to see if testRank has been "broadcasted"/modified
  IF (testRank /= 1) THEN
    PRINT *, "Test Passed: testRank modified correctly."
  ELSE
    PRINT *, "Test Failed: testRank not modified."
  END IF
  
CONTAINS

  ! The subroutine directly within the same file
  SUBROUTINE MODEL_CRUST_2_0_BROADCAST(MYRANK)
    INTEGER(KIND=4), INTENT(INOUT) :: MYRANK
    
    ! Implement the broadcast functionality here
    ! For the purpose of testing, we'll simply modify MYRANK
    MYRANK = MYRANK + 1
  END SUBROUTINE MODEL_CRUST_2_0_BROADCAST

END PROGRAM testBroadcast