MODULE COMPUTE_STACEY_CM_BACKWARD__genmod
  IMPLICIT NONE
CONTAINS
  SUBROUTINE COMPUTE_STACEY_CM_BACKWARD(inputArray, outputArray, size)
    INTEGER, INTENT(IN) :: size
    REAL, DIMENSION(size), INTENT(IN) :: inputArray
    REAL, DIMENSION(size-1), INTENT(OUT) :: outputArray
    INTEGER :: i
    DO i = 2, size
      outputArray(i-1) = inputArray(i) - inputArray(i-1)
    END DO
  END SUBROUTINE COMPUTE_STACEY_CM_BACKWARD
END MODULE COMPUTE_STACEY_CM_BACKWARD__genmod

PROGRAM main
  USE COMPUTE_STACEY_CM_BACKWARD__genmod
  IMPLICIT NONE
  INTEGER :: size
  REAL, ALLOCATABLE :: inputArray(:), outputArray(:)

  ! Example usage of the subroutine
  size = 5
  ALLOCATE(inputArray(size))
  ALLOCATE(outputArray(size-1))

  inputArray = [1.0, 2.0, 4.0, 7.0, 11.0]

  CALL COMPUTE_STACEY_CM_BACKWARD(inputArray, outputArray, size)

  PRINT *, "Output Array:"
  PRINT *, outputArray

  DEALLOCATE(inputArray)
  DEALLOCATE(outputArray)
END PROGRAM main