MODULE mod_t
  IMPLICIT NONE

  TYPE :: t
    INTEGER :: x
  END TYPE t

  INTERFACE OPERATOR(==)
    MODULE PROCEDURE t_eq
  END INTERFACE

  INTERFACE OPERATOR(.FOO.)
    MODULE PROCEDURE t_foo
  END INTERFACE

CONTAINS

  FUNCTION t_foo(this, other) RESULT(res)
    TYPE(t), INTENT(IN) :: this, other
    LOGICAL :: res
    res = .FALSE.
  END FUNCTION t_foo

  FUNCTION t_eq(this, other) RESULT(res)
    TYPE(t), INTENT(IN) :: this, other
    LOGICAL :: res
    res = (this%x == other%x)
  END FUNCTION t_eq

END MODULE mod_t

PROGRAM test_mod_t
  USE mod_t
  IMPLICIT NONE

  TYPE(t) :: obj1, obj2
  LOGICAL :: test_result

  ! Initialize objects
  obj1%x = 1
  obj2%x = 1

  ! Test the == operator
  test_result = (obj1 == obj2)
  PRINT *, "obj1 == obj2: ", test_result

  ! Test the .FOO. operator
  test_result = obj1 .FOO. obj2
  PRINT *, "obj1 .FOO. obj2: ", test_result

END PROGRAM test_mod_t