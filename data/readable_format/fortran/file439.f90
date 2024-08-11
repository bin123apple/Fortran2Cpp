MODULE complex_mod
  IMPLICIT NONE
  PRIVATE
  PUBLIC :: cx, OPERATOR(+), OPERATOR(==)

  TYPE cx
    INTEGER :: re
    INTEGER :: im
  END TYPE cx

  INTERFACE OPERATOR (+)
    MODULE PROCEDURE add_cx_cx, add_cx_int
  END INTERFACE

  INTERFACE OPERATOR (==)
    MODULE PROCEDURE eq_cx
  END INTERFACE

CONTAINS

  FUNCTION add_cx_cx(a, b) RESULT(c)
    TYPE(cx), INTENT(IN) :: a, b
    TYPE(cx) :: c
    c%re = a%re + b%re
    c%im = a%im + b%im
  END FUNCTION add_cx_cx

  FUNCTION add_cx_int(a, i) RESULT(c)
    TYPE(cx), INTENT(IN) :: a
    INTEGER, INTENT(IN) :: i
    TYPE(cx) :: c
    c%re = a%re + i
    c%im = a%im
  END FUNCTION add_cx_int

  FUNCTION eq_cx(a, b) RESULT(equality)
    TYPE(cx), INTENT(IN) :: a, b
    LOGICAL :: equality
    equality = (a%re == b%re) .AND. (a%im == b%im)
  END FUNCTION eq_cx

END MODULE complex_mod

PROGRAM test_complex_numbers
  USE complex_mod
  IMPLICIT NONE

  TYPE(cx) :: a, c
  LOGICAL :: test_result
  INTEGER :: b = 3

  a = cx(1, 2)

  ! Test addition of cx and integer
  c = a + b
  IF (.NOT.(c == cx(4, 2))) THEN
    PRINT *, "Test 1 Failed"
  ELSE
    PRINT *, "Test 1 Passed"
  END IF

  ! Test equality
  test_result = (c == cx(4, 2))
  IF (.NOT. test_result) THEN
    PRINT *, "Test 2 Failed"
  ELSE
    PRINT *, "Test 2 Passed"
  END IF

  PRINT *, "All tests passed successfully!"

END PROGRAM test_complex_numbers