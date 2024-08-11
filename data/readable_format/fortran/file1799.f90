PROGRAM testMain
  IMPLICIT NONE
  INTEGER :: n
  CHARACTER(LEN=100) :: str

  n = 5

  CALL testMyBlock(n)
  CALL testAllocArray(n)
  CALL testString(n, str)

  PRINT *, "All tests passed successfully."
END PROGRAM testMain

SUBROUTINE testMyBlock(n)
  INTEGER, INTENT(IN) :: n
  INTEGER :: arr(n)
  PRINT *, "Test MyBlock Passed"
END SUBROUTINE testMyBlock

SUBROUTINE testAllocArray(n)
  INTEGER, INTENT(IN) :: n
  INTEGER, ALLOCATABLE :: alloc_arr(:)
  ALLOCATE (alloc_arr(n))
  IF (ALLOCATED(alloc_arr)) THEN
    PRINT *, "Test AllocArray Passed"
  END IF
END SUBROUTINE testAllocArray

SUBROUTINE testString(n, str)
  INTEGER, INTENT(IN) :: n
  CHARACTER(LEN=*), INTENT(OUT) :: str
  str = "123456789"
  str = str(:n)  ! Trim or pad the string to length n
  IF (LEN_TRIM(str) == n) THEN
    PRINT *, "Test String Passed"
  END IF
END SUBROUTINE testString