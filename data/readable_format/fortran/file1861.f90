PROGRAM TestALPCLR
  CHARACTER*3 :: dev1

  ! Initialize the variable
  dev1 = 'ABC'
  
  ! Call the subroutine
  CALL ALPCLR(dev1)
  
  ! Optionally print the result to verify the behavior
  PRINT *, 'DEV1 = ', dev1
END PROGRAM TestALPCLR


SUBROUTINE ALPCLR(DEV1)
  CHARACTER*3 DEV1
  ! As per your original code, this subroutine does nothing.
  RETURN
END SUBROUTINE ALPCLR