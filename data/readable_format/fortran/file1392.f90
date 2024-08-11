! Define a module containing the function
MODULE my_functions
  IMPLICIT NONE
CONTAINS
  INTEGER FUNCTION f()
    f = 42
  END FUNCTION f
END MODULE my_functions

! Main program to test the function
PROGRAM test
  USE my_functions
  IMPLICIT NONE
  INTEGER :: expected, result

  expected = 42
  result = f()

  IF (result == expected) THEN
    PRINT *, "Test Passed: f() = ", result
  ELSE
    PRINT *, "Test Failed: f() = ", result, ", Expected: ", expected
  END IF
END PROGRAM test