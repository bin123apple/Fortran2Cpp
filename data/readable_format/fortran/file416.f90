PROGRAM MAIN
  IMPLICIT NONE
  TYPE :: t
     INTEGER :: dummy = 0
  END TYPE t
  CLASS(t), POINTER :: a
  TYPE(t), TARGET :: b
  CLASS(t), ALLOCATABLE :: c

  ! Test
  b%dummy = 5
  a => b
  CALL SUB(a)
  IF (.NOT. ASSOCIATED(a)) THEN
     PRINT *, "Test failed: a is not associated."
  ELSE
     PRINT *, "Test passed: a is associated."
  END IF
CONTAINS
  SUBROUTINE SUB(a)
    CLASS(t), POINTER :: a
    a => NULL()
    ! Test for subroutine
    PRINT *, "Subroutine SUB was called."
  END SUBROUTINE SUB
END PROGRAM MAIN