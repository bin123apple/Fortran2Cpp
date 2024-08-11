PROGRAM ExampleProgram
  IMPLICIT NONE
  DOUBLE PRECISION :: X(5) = (/1.0, 2.0, 3.0, 4.0, 5.0/)
  DOUBLE PRECISION :: V(5)
  INTEGER :: K = 5
  INTEGER :: i

  ! Call the subroutine
  CALL FJAC(X, V, K)

  ! Output the result
  DO i = 1, K
     PRINT *, "X(", i, ") = ", X(i)
  END DO

END PROGRAM ExampleProgram

SUBROUTINE FJAC(X, V, K)
  IMPLICIT NONE
  DOUBLE PRECISION, INTENT(INOUT) :: X(*)
  DOUBLE PRECISION, INTENT(IN) :: V(*)
  INTEGER, INTENT(IN) :: K
  INTEGER :: i

  DO i = 1, K
     X(i) = X(i) + 1
  END DO

END SUBROUTINE FJAC

FUNCTION add_one(val)
  DOUBLE PRECISION, INTENT(IN) :: val
  DOUBLE PRECISION :: add_one

  add_one = val + 1.0

END FUNCTION add_one