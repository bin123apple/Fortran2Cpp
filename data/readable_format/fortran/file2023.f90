MODULE GIDRES__genmod
  INTERFACE 
    SUBROUTINE GIDRES(INC)
      INTEGER(KIND=4), INTENT(IN) :: INC
    END SUBROUTINE GIDRES
  END INTERFACE 
END MODULE GIDRES__genmod

! Define the subroutine outside the module but in the same file
SUBROUTINE GIDRES(INC)
  INTEGER(KIND=4), INTENT(IN) :: INC
  PRINT *, "GIDRES called with INC =", INC
END SUBROUTINE GIDRES

! Main program that uses the module and calls the subroutine
PROGRAM Main
  USE GIDRES__genmod
  INTEGER(KIND=4) :: InputValue
  
  ! Assign a value to InputValue or get it from user input, for example:
  InputValue = 42
  
  ! Call the subroutine
  CALL GIDRES(InputValue)
END PROGRAM Main