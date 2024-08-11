MODULE othermod
  IMPLICIT NONE
CONTAINS
  SUBROUTINE othersub()
    PRINT *, "othersub called"
  END SUBROUTINE othersub
END MODULE othermod

MODULE testmod
  USE othermod
  IMPLICIT NONE

  TYPE :: t1
  CONTAINS
    PROCEDURE :: proc1
    PROCEDURE :: proc2
  END TYPE t1

  TYPE :: t2
    INTEGER :: x
  CONTAINS
    PROCEDURE :: proc3
  END TYPE t2

CONTAINS

  SUBROUTINE proc1(this)
    CLASS(t1), INTENT(INOUT) :: this
    PRINT *, "proc1 called"
  END SUBROUTINE proc1

  FUNCTION proc2(this, x) RESULT(res)
    CLASS(t1), INTENT(INOUT) :: this
    REAL :: x, res
    res = x / 2.0
    PRINT *, "proc2 called with x =", x, "result is", res
  END FUNCTION proc2

  FUNCTION proc3(this) RESULT(res)
    CLASS(t2), INTENT(INOUT) :: this
    INTEGER :: res
    res = 42
    PRINT *, "proc3 called, result is", res
  END FUNCTION proc3

END MODULE testmod

PROGRAM testProgram
  USE testmod
  IMPLICIT NONE
  TYPE(t1) :: obj1
  TYPE(t2) :: obj2
  REAL :: result2
  INTEGER :: result3

  CALL obj1%proc1()
  result2 = obj1%proc2(4.0)
  result3 = obj2%proc3()

  PRINT *, "Test proc2 result:", result2
  PRINT *, "Test proc3 result:", result3
END PROGRAM testProgram