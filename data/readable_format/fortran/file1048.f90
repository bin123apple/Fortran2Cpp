PROGRAM testFunctions
  IMPLICIT NONE
  REAL :: testVal, testVal2

  ! Test ABSF
  testVal = -5.0
  PRINT *, 'ABSF(-5.0) = ', ABSF(testVal)  ! Expected: 5.0

  ! Test SIGNF
  testVal = -5.0
  testVal2 = 3.0
  PRINT *, 'SIGNF(-5.0, 3.0) = ', SIGNF(testVal, testVal2)  ! Expected: 5.0
  
  testVal2 = -3.0
  PRINT *, 'SIGNF(-5.0, -3.0) = ', SIGNF(testVal, testVal2)  ! Expected: -5.0

  ! Test INTF
  testVal = 5.8
  PRINT *, 'INTF(5.8) = ', INTF(testVal)  ! Expected: 5.0

  ! Test SQRTF
  testVal = 16.0
  PRINT *, 'SQRTF(16.0) = ', SQRTF(testVal)  ! Expected: 4.0

  ! Test SINF
  testVal = 0.5
  PRINT *, 'SINF(0.5) = ', SINF(testVal)  ! Expected: Approx. 0.4794
  
  ! Test COSF
  PRINT *, 'COSF(0.5) = ', COSF(testVal)  ! Expected: Approx. 0.8776
  
  ! Test ARCOSF
  PRINT *, 'ARCOSF(0.5) = ', ARCOSF(testVal)  ! Expected: Approx. 1.0472
  
  ! Test ARSINF
  PRINT *, 'ARSINF(0.5) = ', ARSINF(testVal)  ! Expected: Approx. 0.5236
  
  ! Test ATN1F
  testVal2 = 1.0
  PRINT *, 'ATN1F(1.0, 1.0) = ', ATN1F(testVal, testVal2)  ! Expected: Approx. 0.7854
  
  ! Test CLOCKF - Just run it since it's time-dependent
  PRINT *, 'CLOCKF(0) = ', CLOCKF(0.0)

CONTAINS

  FUNCTION ABSF (X)
    REAL :: ABSF, X
    ABSF = ABS(X)
  END FUNCTION ABSF

  FUNCTION SIGNF (X,Y)
    REAL :: SIGNF, X, Y
    SIGNF = SIGN(X,Y)
  END FUNCTION SIGNF

  REAL FUNCTION INTF (X)
    REAL :: X
    INTF = AINT(X)
  END FUNCTION INTF

  FUNCTION SQRTF (X)
    REAL :: SQRTF, X
    SQRTF = SQRT (X)
  END FUNCTION SQRTF

  FUNCTION SINF (X)
    REAL :: SINF, X
    SINF = SIN (X)
  END FUNCTION SINF

  FUNCTION COSF (X)
    REAL :: COSF, X
    COSF = COS (X)
  END FUNCTION COSF

  FUNCTION ARCOSF (X)
    REAL :: ARCOSF, X
    ARCOSF = ACOS (X)
  END FUNCTION ARCOSF

  FUNCTION ARSINF (X)
    REAL :: ARSINF, X
    ARSINF = ASIN (X)
  END FUNCTION ARSINF

  FUNCTION ATN1F (X,Y)
    REAL :: ATN1F, X, Y
    ATN1F = ATAN2 (X,Y)
  END FUNCTION ATN1F

  FUNCTION CLOCKF (XX)
    REAL :: CLOCKF, XX
    INTEGER :: COUNT_NOW, COUNT_RATE, COUNT_MAX
    CALL SYSTEM_CLOCK(COUNT_NOW, COUNT_RATE, COUNT_MAX)  
    CLOCKF = (COUNT_NOW / 60.0) / COUNT_RATE
  END FUNCTION CLOCKF

END PROGRAM testFunctions