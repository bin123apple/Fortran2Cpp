PROGRAM test

PROCEDURE(add), POINTER :: f
logical :: g

! Main program logic tests
g=greater(4.,add(1.,2.))
if (.not. g) call abort()

f => add
g=greater(4.,f(1.,2.))
if (.not. g) call abort()

! Unit tests
CALL test_add()
CALL test_greater()
CALL test_procedure_pointer()

CONTAINS

REAL FUNCTION add(x,y)
  REAL, INTENT(in) :: x,y
  add = x+y
END FUNCTION add

LOGICAL FUNCTION greater(x,y)
  REAL, INTENT(in) :: x, y
  greater = (x > y)
END FUNCTION greater

! Unit test for add function
SUBROUTINE test_add()
  REAL :: result
  result = add(2., 3.)
  IF (result /= 5.) CALL abort()
  PRINT *, "test_add passed."
END SUBROUTINE test_add

! Unit test for greater function
SUBROUTINE test_greater()
  IF (.not. greater(5., 3.)) CALL abort()
  IF (greater(2., 3.)) CALL abort()
  PRINT *, "test_greater passed."
END SUBROUTINE test_greater

! Unit test for procedure pointer and logical operation
SUBROUTINE test_procedure_pointer()
  PROCEDURE(add), POINTER :: f_test
  logical :: g_test
  
  f_test => add
  g_test = greater(4., f_test(1., 2.))
  IF (.not. g_test) CALL abort()
  PRINT *, "test_procedure_pointer passed."
END SUBROUTINE test_procedure_pointer

END PROGRAM test