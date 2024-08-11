MODULE myModule
  IMPLICIT NONE
CONTAINS
  FUNCTION myFunction(x) RESULT(y)
    INTEGER, INTENT(IN) :: x
    INTEGER :: y
    y = x * 2
  END FUNCTION myFunction
END MODULE myModule

PROGRAM test_myFunction
  USE myModule
  IMPLICIT NONE
  INTEGER :: result

  result = myFunction(5)
  IF (result == 10) THEN
    PRINT *, "Test passed: The result is: ", result
  ELSE
    PRINT *, "Test failed: The result is: ", result
  END IF
END PROGRAM test_myFunction