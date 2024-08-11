PROGRAM testCDIV
  REAL AR,AI,BR,BI,CR,CI
  
  ! Test case 1
  AR = 5.0
  AI = 3.0
  BR = 2.0
  BI = 4.0
  CALL CDIV(AR,AI,BR,BI,CR,CI)
  PRINT *, "Test Case 1: CR=", CR, "CI=", CI
  
  ! Add more test cases as needed
  
END PROGRAM testCDIV

SUBROUTINE CDIV (AR, AI, BR, BI, CR, CI)
  REAL AR,AI,BR,BI,CR,CI
  REAL S,ARS,AIS,BRS,BIS
  S = ABS(BR) + ABS(BI)
  ARS = AR/S
  AIS = AI/S
  BRS = BR/S
  BIS = BI/S
  S = BRS**2 + BIS**2
  CR = (ARS*BRS + AIS*BIS)/S
  CI = (AIS*BRS - ARS*BIS)/S
  RETURN
END