PROGRAM TestGRMCUR
  IMPLICIT NONE

  INTEGER :: ICX, ICY, ICH

  ! Test case 1
  ICX = 10
  ICY = 20
  ICH = -1
  CALL GRMCUR(ICH, ICX, ICY)
  IF (ICY == 24) THEN
     PRINT *, "Test 1 Passed"
  ELSE
     PRINT *, "Test 1 Failed"
  END IF
  
  ! Add more test cases as needed

END PROGRAM TestGRMCUR

SUBROUTINE GRMCUR (ICH, ICX, ICY)
  INTEGER ICH, ICX, ICY
  INTEGER STEP
  SAVE STEP
  DATA STEP /4/
  IF (ICH.EQ.-1 .OR. ICH.EQ.-28) THEN
      ICY = ICY+STEP
  ELSE IF (ICH.EQ.-2 .OR. ICH.EQ.-22) THEN
      ICY = ICY-STEP
  ELSE IF (ICH.EQ.-3 .OR. ICH.EQ.-26) THEN
      ICX = ICX+STEP
  ELSE IF (ICH.EQ.-4 .OR. ICH.EQ.-24) THEN
      ICX = ICX-STEP
  ELSE IF (ICH.EQ.-27) THEN
      ICX = ICX-STEP
      ICY = ICY+STEP
  ELSE IF (ICH.EQ.-29) THEN
      ICX = ICX+STEP
      ICY = ICY+STEP
  ELSE IF (ICH.EQ.-23) THEN
      ICX = ICX+STEP
      ICY = ICY-STEP
  ELSE IF (ICH.EQ.-21) THEN
      ICX = ICX-STEP
      ICY = ICY-STEP
  ELSE IF (ICH.EQ.-11) THEN
      STEP = 1
  ELSE IF (ICH.EQ.-12) THEN
      STEP = 4
  ELSE IF (ICH.EQ.-13) THEN
      STEP = 16
  ELSE IF (ICH.EQ.-14) THEN
      STEP = 64
  END IF
END SUBROUTINE GRMCUR