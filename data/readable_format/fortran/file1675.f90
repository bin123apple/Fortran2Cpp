PROGRAM testSecond
  REAL :: result

  result = SECOND()
  IF (result == 0.0E+0) THEN
    PRINT *, 'Test Passed!'
  ELSE
    PRINT *, 'Test Failed!'
  END IF
END PROGRAM testSecond

REAL FUNCTION SECOND()
    SECOND = 0.0E+0
    RETURN
END FUNCTION SECOND