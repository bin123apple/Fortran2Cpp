MODULE hello_constants
  CHARACTER(*), PARAMETER :: hello_string = 'Hello World!'
END MODULE hello_constants

PROGRAM test_hello_constants
  USE hello_constants
  IMPLICIT NONE
  CHARACTER(*), PARAMETER :: expected_string = 'Hello World!'

  WRITE(*,*) 'Testing hello_string...'
  IF (hello_string == expected_string) THEN
    WRITE(*,*) 'Test passed: hello_string matches expected_string'
  ELSE
    WRITE(*,*) 'Test failed: hello_string does not match expected_string'
  END IF
END PROGRAM test_hello_constants