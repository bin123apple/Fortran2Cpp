MODULE EGOPS_Utilities
CONTAINS
  FUNCTION dirname(fullfilename)
    CHARACTER(LEN=*), INTENT(IN) :: fullfilename
    CHARACTER(LEN=LEN(fullfilename)) :: dirname
    dirname = ''  ! This is a placeholder; you'd implement the logic here.
  END FUNCTION dirname
END MODULE EGOPS_Utilities

MODULE AtmoIono
  USE EGOPS_Utilities
  CHARACTER(LEN=10), PARAMETER :: ComputeDryAtmModel = 'Dry Atm.  '

  TYPE AtmModel
    CHARACTER (LEN=LEN(ComputeDryAtmModel)) :: moistDryStr
  END TYPE AtmModel
END MODULE AtmoIono

! Example program that uses the modules
PROGRAM AtmoIonoSphere
  USE AtmoIono
  IMPLICIT NONE

  TYPE(AtmModel) :: model
  CHARACTER(LEN=100) :: path, dir

  path = "/path/to/somefile.ext"
  dir = dirname(path)

  PRINT *, "Directory name: ", dir
  PRINT *, "Model default string: ", model%moistDryStr
END PROGRAM AtmoIonoSphere