module data_diag
  implicit none
  public
  logical               :: dump_mesh_info_files = .false.
  logical               :: dump_mesh_info_screen = .false.
  logical               :: dump_mesh_vtk = .false.
  logical               :: dump_1dmodel = .false.
  logical               :: only_suggest_ntheta = .false.
  character(len=200)    :: diagpath = " "
  integer               :: lfdiag = 0
end module data_diag

program test_data_diag
  use data_diag
  implicit none

  ! Set module variables for testing purposes
  dump_mesh_info_files = .true.
  dump_mesh_info_screen = .true.
  dump_mesh_vtk = .true.
  dump_1dmodel = .true.
  only_suggest_ntheta = .true.
  diagpath = "path/to/diagnostics"
  lfdiag = 123

  ! Output the values to verify correct behavior
  print *, "dump_mesh_info_files: ", dump_mesh_info_files
  print *, "dump_mesh_info_screen: ", dump_mesh_info_screen
  print *, "dump_mesh_vtk: ", dump_mesh_vtk
  print *, "dump_1dmodel: ", dump_1dmodel
  print *, "only_suggest_ntheta: ", only_suggest_ntheta
  print *, "diagpath: ", diagpath
  print *, "lfdiag: ", lfdiag
end program test_data_diag