MODULE math_operations
  IMPLICIT NONE
CONTAINS
  FUNCTION square(n) RESULT(res)
    INTEGER, INTENT(IN) :: n
    INTEGER :: res
    res = n*n
  END FUNCTION square
END MODULE math_operations

PROGRAM test_program
  USE math_operations
  IMPLICIT NONE
  INTEGER :: number, result
  
  number = 4
  result = square(number)
  PRINT *, "The square of ", number, " is ", result
END PROGRAM test_program