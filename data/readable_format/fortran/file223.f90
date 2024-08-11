MODULE math_operations
  IMPLICIT NONE
CONTAINS
  ! Function to add two numbers
  FUNCTION add(a, b)
    REAL, INTENT(IN) :: a, b
    REAL :: add
    add = a + b
  END FUNCTION add
END MODULE math_operations

PROGRAM test_program
  USE math_operations
  IMPLICIT NONE
  REAL :: number1, number2, result
  
  ! Example values for demonstration
  number1 = 5.0
  number2 = 3.0
  
  result = add(number1, number2)
  PRINT *, "The result of adding ", number1, " and ", number2, " is ", result
END PROGRAM test_program