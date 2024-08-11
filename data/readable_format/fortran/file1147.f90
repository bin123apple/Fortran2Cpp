PROGRAM P
  IMPLICIT NONE
  REAL :: A
  INTEGER :: I
  
  A = 3.4
  I = 3
  
  CALL TestVariables(A, I)
  
END PROGRAM P

SUBROUTINE TestVariables(A, I)
  IMPLICIT NONE
  REAL, INTENT(IN) :: A
  INTEGER, INTENT(IN) :: I
  
  IF (A == 3.4 .AND. I == 3) THEN
    PRINT *, "Test Passed"
  ELSE
    PRINT *, "Test Failed"
  END IF
  
END SUBROUTINE TestVariables