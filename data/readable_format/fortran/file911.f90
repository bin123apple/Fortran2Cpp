PROGRAM testHello
  IMPLICIT NONE
  CHARACTER(LEN=20) :: output
  ! Redirect standard output to a string or file, then compare
  ! This is pseudocode and conceptual; actual implementation may vary significantly
  CALL execute_command_line('hello > hello_output.txt')
  OPEN(UNIT=10, FILE='hello_output.txt', STATUS='old', ACTION='read')
  READ(10, '(A)') output
  IF (TRIM(output) == 'Hello, world!') THEN
    PRINT *, 'Test passed!'
  ELSE
    PRINT *, 'Test failed!'
  END IF
  CLOSE(UNIT=10)
END PROGRAM testHello