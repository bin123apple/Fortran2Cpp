MODULE m
  TYPE :: t1
    INTEGER :: a = 42, b
  END TYPE t1

  TYPE :: t2
    INTEGER :: a, b
  END TYPE t2

  CONTAINS
    SUBROUTINE sub1(x)
      TYPE(t1), INTENT(OUT) :: x
      ! x%a is already initialized to 42 by default
    END SUBROUTINE sub1

    SUBROUTINE sub2(x)
      TYPE(t2), INTENT(OUT) :: x
      x%a = 42
      ! x%b remains uninitialized
    END SUBROUTINE sub2

    SUBROUTINE sub3(x)
      TYPE(t2), INTENT(OUT) :: x
      ! This subroutine intentionally left blank.
    END SUBROUTINE sub3
END MODULE m

PROGRAM test_m
  USE m
  IMPLICIT NONE
  TYPE(t1) :: x1
  TYPE(t2) :: x2, x3

  CALL sub1(x1)
  PRINT *, "sub1 - x1%a should be 42:", x1%a
  PRINT *, "sub1 - x1%b is uninitialized and may vary."

  CALL sub2(x2)
  PRINT *, "sub2 - x2%a should be 42:", x2%a
  PRINT *, "sub2 - x2%b is uninitialized and may vary."

  CALL sub3(x3)
  PRINT *, "sub3 - Initial values of x3 may vary as it is not modified by sub3."

END PROGRAM test_m