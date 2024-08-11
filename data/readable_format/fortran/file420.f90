! Define the subroutine GRFLUN in the same file
SUBROUTINE GRFLUN(LUN)
  INTEGER, INTENT(INOUT) :: LUN
  LUN = 0
END SUBROUTINE GRFLUN

! Main program to test the GRFLUN subroutine
PROGRAM testGRFLUN
  IMPLICIT NONE
  INTEGER :: LUN

  ! Initialize LUN with a non-zero value
  LUN = 5
  ! Call the subroutine GRFLUN
  CALL GRFLUN(LUN)

  ! Check if LUN has been set to 0 after the call
  IF (LUN == 0) THEN
    PRINT *, 'Test passed: LUN is 0'
  ELSE
    PRINT *, 'Test failed: LUN is not 0'
  END IF
END PROGRAM testGRFLUN