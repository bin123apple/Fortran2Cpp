! CombinedModuleAndTest.f90
MODULE StringParser
  IMPLICIT NONE
  INTEGER, PARAMETER :: MaxStringLength=132
  INTEGER, PARAMETER :: MaxStringTokens=100
  CHARACTER(LEN=MaxStringLength), ALLOCATABLE :: StringParts(:)
END MODULE StringParser

PROGRAM TestStringParser
  USE StringParser
  IMPLICIT NONE

  INTEGER :: i

  ! Allocate the StringParts array
  ALLOCATE(StringParts(MaxStringTokens))
  
  ! Assign some values and print them
  DO i = 1, MaxStringTokens
    WRITE(StringParts(i), '(A, I3)') "Token", i
    PRINT *, StringParts(i)
  END DO

  ! Clean-up
  DEALLOCATE(StringParts)
  
END PROGRAM TestStringParser