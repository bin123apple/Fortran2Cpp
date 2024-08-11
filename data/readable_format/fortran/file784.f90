! program_and_test.f90
SUBROUTINE test(str)
  CHARACTER(len=*), INTENT(IN) :: str
  PRINT *, 'Testing with string:', str
END SUBROUTINE test

PROGRAM main
  CALL test('abc')
END PROGRAM main