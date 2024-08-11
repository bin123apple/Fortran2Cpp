PROGRAM testCORERD
  IMPLICIT NONE
  REAL*8 :: result
  INTEGER :: KW
  REAL*8 :: MC, M0, MFLASH

  ! Test Case 1
  KW = 14
  MC = 1.0
  M0 = 0.0
  MFLASH = 0.0
  result = CORERD(KW, MC, M0, MFLASH)
  PRINT *, "Test Case 1 (KW=14): ", result

  ! Test Case 2
  KW = 13
  result = CORERD(KW, MC, M0, MFLASH)
  PRINT *, "Test Case 2 (KW=13): ", result

  ! Add more test cases here as needed

CONTAINS

  REAL*8 FUNCTION CORERD(KW, MC, M0, MFLASH)
    IMPLICIT NONE
    INTEGER KW
    REAL*8 MC, M0, MFLASH
    REAL*8 MCH
    PARAMETER (MCH = 1.44d0)

    IF(KW.EQ.14)THEN
       CORERD = 4.24d-06*MC
    ELSEIF(KW.EQ.13)THEN
       CORERD = 1.4d-05
    ELSEIF(KW.LE.1.OR.KW.EQ.7)THEN
       CORERD = 0.d0
    ELSEIF(KW.EQ.4.OR.KW.EQ.5.OR.(KW.LE.3.AND.M0.GT.MFLASH))THEN
       CORERD = 0.2239d0*MC**0.62d0
    ELSE
       CORERD = 0.0115d0*SQRT(MAX(1.48204d-06,(MCH/MC)**(2.d0/3.d0) - (MC/MCH)**(2.d0/3.d0)))
       IF(KW.LE.9) CORERD = 5.d0*CORERD
    ENDIF
  END FUNCTION CORERD

END PROGRAM testCORERD