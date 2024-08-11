PROGRAM testF
  IMPLICIT NONE
  INTERFACE
      FUNCTION f() RESULT (g)
          INTEGER :: g
      END FUNCTION f
  END INTERFACE

  INTEGER :: result
  
  result = f()
  IF (result == 42) THEN
     PRINT *, "Test passed: f() returned 42"
  ELSE
     PRINT *, "Test failed: f() did not return 42"
  END IF
END PROGRAM testF

! The actual implementation of the function should be outside the program unit
FUNCTION f() RESULT (g)
  INTEGER :: g
  SAVE
  g = 42
END FUNCTION f