MODULE WORLD_SPLIT__genmod
  INTERFACE 
    SUBROUTINE WORLD_SPLIT
    END SUBROUTINE WORLD_SPLIT
  END INTERFACE 
END MODULE WORLD_SPLIT__genmod

PROGRAM test_world_split
  USE WORLD_SPLIT__genmod

  ! Call the subroutine to ensure it is linked and callable
  CALL WORLD_SPLIT

  PRINT *, "Fortran test completed successfully."

END PROGRAM test_world_split

SUBROUTINE WORLD_SPLIT
  ! Empty subroutine as per the original code
END SUBROUTINE WORLD_SPLIT