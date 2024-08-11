! Define module foo
MODULE foo
  TYPE type1
    INTEGER :: i1
  END TYPE type1
END MODULE foo

! Define module bar
MODULE bar
  USE foo
  IMPLICIT NONE
CONTAINS
  SUBROUTINE sub1(x, y)
    TYPE(type1), INTENT(IN) :: x
    INTEGER, INTENT(OUT) :: y(x%i1)
    y = 1
  END SUBROUTINE sub1

  SUBROUTINE sub2(u, v)
    TYPE(type1), INTENT(IN) :: u
    INTEGER, INTENT(OUT) :: v(u%i1)
    v = 2
  END SUBROUTINE sub2
END MODULE bar

! Define module foobar
MODULE foobar
  USE foo
  USE bar
  IMPLICIT NONE
CONTAINS
  SUBROUTINE sub3(s, t)
    TYPE(type1), INTENT(IN) :: s
    INTEGER, INTENT(OUT) :: t(s%i1)
    t = 3
  END SUBROUTINE sub3
END MODULE foobar

! Main program
PROGRAM use_foobar
  USE foo
  USE bar
  USE foobar
  IMPLICIT NONE
  INTEGER :: j(3) = 0
  TYPE(type1) :: z
  z%i1 = 3
  CALL sub1(z, j)
  z%i1 = 2
  CALL sub2(z, j)
  z%i1 = 1
  CALL sub3(z, j)
  IF (ALL(j == (/3, 2, 1/))) THEN
    PRINT *, "Test Passed."
  ELSE
    PRINT *, "Test Failed."
    STOP 1
  END IF
END PROGRAM use_foobar