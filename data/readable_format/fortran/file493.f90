PROGRAM main
  IMPLICIT NONE
  REAL, ALLOCATABLE :: A(:)
  INTEGER :: allocStatus

  ! Allocate array A with 10 elements
  ALLOCATE ( A(10), STAT = allocStatus )
  IF (allocStatus /= 0) THEN
    PRINT *, "Allocation failed with status: ", allocStatus
    STOP
  ELSE
    PRINT *, "Allocation successful"
  END IF

  ! Deallocate array A
  DEALLOCATE ( A, STAT = allocStatus )
  IF (allocStatus /= 0) THEN
    PRINT *, "Deallocation failed with status: ", allocStatus
    STOP
  ELSE
    PRINT *, "Deallocation successful"
  END IF
END PROGRAM main