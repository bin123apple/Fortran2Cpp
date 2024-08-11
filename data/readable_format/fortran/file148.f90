PROGRAM test_prog
  IMPLICIT NONE

  TYPE :: ProcPointerType
    PROCEDURE(triple), POINTER, NOPASS :: f
  END TYPE ProcPointerType

  TYPE(ProcPointerType) :: ppt
  REAL :: tres(2)

  ppt%f => triple

  tres = ppt%f(2, [2., 4.])
  CALL assert_close(tres(1), 6., 1E-3)
  CALL assert_close(tres(2), 12., 1E-3)

  tres = ppt%f(2, [3., 5.])
  CALL assert_close(tres(1), 9., 1E-3)
  CALL assert_close(tres(2), 15., 1E-3)

CONTAINS

  FUNCTION triple(n, x) RESULT(tre)
    INTEGER, INTENT(IN) :: n
    REAL, INTENT(IN) :: x(2)
    REAL :: tre(2)
    tre = 3. * x
  END FUNCTION triple

  SUBROUTINE assert_close(a, b, tol)
    REAL, INTENT(IN) :: a, b, tol
    IF (ABS(a - b) > tol) THEN
      PRINT *, "Assertion failed: ", a, "not close to", b
      STOP
    END IF
  END SUBROUTINE assert_close

END PROGRAM test_prog