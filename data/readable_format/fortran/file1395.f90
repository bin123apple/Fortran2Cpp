MODULE SLAPY3Mod
IMPLICIT NONE
CONTAINS
  REAL FUNCTION SLAPY3(X, Y, Z)
    REAL, INTENT(IN) :: X, Y, Z
    REAL :: W, XABS, YABS, ZABS
    XABS = ABS(X)
    YABS = ABS(Y)
    ZABS = ABS(Z)
    W = MAX(XABS, YABS, ZABS)
    IF (W == 0.0) THEN
       SLAPY3 = 0.0
    ELSE
       SLAPY3 = W * SQRT((XABS / W)**2 + (YABS / W)**2 + (ZABS / W)**2)
    END IF
  END FUNCTION SLAPY3
END MODULE SLAPY3Mod

PROGRAM test_slapy3
  USE SLAPY3Mod
  IMPLICIT NONE
  REAL :: result

  result = SLAPY3(3.0, 4.0, 0.0)
  PRINT *, "SLAPY3(3, 4, 0) = ", result, " Expected: 5.0"
  
  result = SLAPY3(1.0, 1.0, 1.0)
  PRINT *, "SLAPY3(1, 1, 1) = ", result, " Expected: ", SQRT(3.0)
  
  result = SLAPY3(0.0, 0.0, 0.0)
  PRINT *, "SLAPY3(0, 0, 0) = ", result, " Expected: 0.0"
  
  result = SLAPY3(-5.0, -12.0, -13.0)
  PRINT *, "SLAPY3(-5, -12, -13) = ", result, " Expected: ", SQRT(5.0**2 + 12.0**2 + 13.0**2)
  
END PROGRAM test_slapy3