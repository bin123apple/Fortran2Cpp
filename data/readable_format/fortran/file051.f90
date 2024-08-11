MODULE mod_behavior
  IMPLICIT NONE
CONTAINS
  FUNCTION get_number() RESULT(number)
    INTEGER :: number
    number = 42
  END FUNCTION get_number
END MODULE mod_behavior

PROGRAM test_mod_behavior
  USE mod_behavior
  IMPLICIT NONE
  INTEGER :: result

  result = get_number()

  WRITE(*,*) 'Testing get_number function...'
  IF (result == 42) THEN
    WRITE(*,*) 'Test passed: ', result
  ELSE
    WRITE(*,*) 'Test failed.'
  END IF
END PROGRAM test_mod_behavior