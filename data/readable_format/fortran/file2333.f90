MODULE M
  IMPLICIT NONE
CONTAINS

  FUNCTION L() RESULT(res)
    USE, INTRINSIC :: ISO_C_BINDING
    LOGICAL(C_BOOL) :: res
    res = .FALSE.
  END FUNCTION L

  FUNCTION L2() RESULT(res)
    LOGICAL(8) :: res
    res = .FALSE._8
  END FUNCTION L2

  SUBROUTINE S()
    DO WHILE (L())
      ! Loop body would execute if L() returns .TRUE.
    ENDDO
    DO WHILE (L2())
      ! Loop body would execute if L2() returns TRUE (non-zero).
    ENDDO
  END SUBROUTINE S

END MODULE M

PROGRAM TestM
  USE M
  IMPLICIT NONE

  ! Test L
  IF (.NOT. L()) THEN
    PRINT *, "Test L passed."
  ELSE
    PRINT *, "Test L failed."
  END IF

  ! Test L2
  IF (.NOT. L2()) THEN
    PRINT *, "Test L2 passed."
  ELSE
    PRINT *, "Test L2 failed."
  END IF

  ! Test S - As S contains no output or return, we assume it passes if the program does not hang
  CALL S()
  PRINT *, "Test S assumed passed (program did not hang)."
END PROGRAM TestM