PROGRAM TestSub
  IMPLICIT NONE
  REAL :: A
  INTEGER :: I
  
  INTERFACE
     SUBROUTINE SUB(A, I)
       REAL, INTENT(INOUT) :: A
       INTEGER, OPTIONAL, INTENT(IN) :: I
     END SUBROUTINE SUB
  END INTERFACE
  
  ! Test 1: Call SUB without optional parameter
  A = 10.0
  CALL SUB(A)
  PRINT *, 'Test 1 - A should be 10.0: ', A
  
  ! Test 2: Call SUB with optional parameter
  A = 20.0
  I = 5
  CALL SUB(A, I)
  PRINT *, 'Test 2 - A should be 20.0, I should be 5: ', A, I

END PROGRAM TestSub

SUBROUTINE SUB(A, I)
  REAL, INTENT(INOUT) :: A
  INTEGER, OPTIONAL, INTENT(IN) :: I
  
  ! Normally, you would perform some operations here
  IF (PRESENT(I)) THEN
    PRINT *, 'I is provided: ', I
  ELSE
    PRINT *, 'I is not provided'
  END IF
END SUBROUTINE