MODULE math_operations
  IMPLICIT NONE
CONTAINS
  FUNCTION add(a, b)
    INTEGER, INTENT(IN) :: a, b
    INTEGER :: add
    add = a + b
  END FUNCTION add
END MODULE math_operations

PROGRAM test_add_function
  USE math_operations
  IMPLICIT NONE
  INTEGER :: result

  result = add(2, 3)
  IF (result == 5) THEN
    PRINT *, "Test passed."
  ELSE
    PRINT *, "Test failed."
  END IF
END PROGRAM test_add_function