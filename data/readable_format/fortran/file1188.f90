PROGRAM testIntOps
  IMPLICIT NONE
  INTEGER :: x, y, result
  INTEGER :: int_func

  ! Test the subroutine
  x = 5
  CALL int_sub(x, y)
  PRINT *, "Subroutine result for x = 5: ", y

  IF (y == 6) THEN
    PRINT *, "Subroutine test PASSED"
  ELSE
    PRINT *, "Subroutine test FAILED"
  END IF

  ! Test the function
  x = 5
  result = int_func(x)
  PRINT *, "Function result for x = 5: ", result

  IF (result == 6) THEN
    PRINT *, "Function test PASSED"
  ELSE
    PRINT *, "Function test FAILED"
  END IF
END PROGRAM testIntOps

! Assuming the original subroutine and function definitions follow here or are included from another file.

SUBROUTINE int_sub(x,y)
  INTEGER, INTENT(in) :: x
  INTEGER, INTENT(out) :: y
  y = x + 1
END SUBROUTINE int_sub

FUNCTION int_func(x) RESULT(res)
  INTEGER, INTENT(in) :: x
  INTEGER :: res
  res = x + 1
END FUNCTION int_func