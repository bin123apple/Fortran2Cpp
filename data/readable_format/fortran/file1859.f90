MODULE hmixing_mod
  IMPLICIT NONE
  CONTAINS
    FUNCTION add_numbers(a, b)
      INTEGER, INTENT(IN) :: a, b
      INTEGER :: add_numbers
      
      add_numbers = a + b
    END FUNCTION add_numbers
END MODULE hmixing_mod

PROGRAM test_hmixing
  USE hmixing_mod
  IMPLICIT NONE

  INTEGER :: result

  ! Test the add_numbers function
  result = add_numbers(2, 3)
  IF (result == 5) THEN
    PRINT *, 'Test passed: 2 + 3 = ', result
  ELSE
    PRINT *, 'Test failed: 2 + 3 did not equal 5'
  END IF
END PROGRAM test_hmixing