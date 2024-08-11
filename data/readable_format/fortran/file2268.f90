! plugin_module.f90
MODULE plugin_module
  IMPLICIT NONE
CONTAINS
  SUBROUTINE plugin_scf_energy()
    PRINT *, "Fortran Stdout: plugin_scf_energy executed."
  END SUBROUTINE plugin_scf_energy
END MODULE plugin_module

! test_plugin_scf_energy.f90
PROGRAM test_plugin_scf_energy
  USE plugin_module
  IMPLICIT NONE
  CALL plugin_scf_energy()
  PRINT *, "Test for plugin_scf_energy subroutine executed successfully."
END PROGRAM test_plugin_scf_energy