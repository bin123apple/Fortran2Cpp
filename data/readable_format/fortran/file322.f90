! combined.f90
PROGRAM Main
  IMPLICIT NONE
  INTEGER :: x

  x = 5
  CALL S(x)
  PRINT *, "After calling S, x = ", x

  ! Insert here the calls to other subroutines or functions you might have
END PROGRAM Main

SUBROUTINE S(P)
  IMPLICIT NONE
  INTEGER, INTENT(INOUT) :: P
  P = P + 1
END SUBROUTINE S

! You can add more subroutines or functions below