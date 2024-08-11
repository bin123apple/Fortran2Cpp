PROGRAM main
  IMPLICIT NONE
  INTEGER :: a
  CALL test(a)
END PROGRAM main

SUBROUTINE test(a)
  IMPLICIT NONE
  INTEGER, INTENT(OUT) :: a

  a = 42
  IF (a /= 42) THEN
    PRINT *, 'Test failed.'
  ELSE
    PRINT *, 'Test passed.'
  END IF
END SUBROUTINE test