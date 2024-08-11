! globalvar_mod.f90
MODULE globalvar_mod
  integer :: xstop
CONTAINS
  SUBROUTINE test_xstop()
    xstop = 5
    IF (xstop /= 5) THEN
      PRINT *, 'Test failed: xstop is not 5.'
    ELSE
      PRINT *, 'Test passed: xstop is 5.'
    END IF
  END SUBROUTINE test_xstop
END MODULE globalvar_mod

PROGRAM test
  USE globalvar_mod
  CALL test_xstop()
END PROGRAM test