PROGRAM P
  IMPLICIT NONE
  INTEGER :: status
  
  PRINT *, "Calling S subroutine"
  CALL S(status)
  
  IF (status == 0) THEN
     PRINT *, "S executed with STOP 0 behavior."
  ELSE
     PRINT *, "S did not execute as expected."
  END IF

  STOP 1
CONTAINS

   SUBROUTINE S(status)
      INTEGER, INTENT(OUT) :: status
      PRINT *, "Inside S subroutine, simulating STOP 0."
      status = 0  ! Simulate STOP 0 behavior by setting status
      ! Normally, we'd use STOP 0 here, but for demonstration, we're simulating it
   END SUBROUTINE S
END PROGRAM P