MODULE globals
  ! Use the BIND(C) attribute to ensure the type is compatible with COMMON blocks
  TYPE, BIND(C) :: type1
     INTEGER :: x
  END TYPE type1
  ! Declare the global variable within the module to ensure visibility
  TYPE(type1) :: pdm_bps
END MODULE globals

PROGRAM main
  USE globals
  ! The external declaration is no longer necessary due to module use.
  
  ! Initialize pdm_bps
  pdm_bps%x = 10
  
  CALL print_values
END PROGRAM main

SUBROUTINE print_values
  USE globals
  ! The external and common declaration is no longer necessary due to module use.
  
  PRINT *, "pdm_bps%x = ", pdm_bps%x
END SUBROUTINE print_values