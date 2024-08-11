module rrlw_tbl

  implicit none
  save

  integer, parameter :: ntbl = 10000
  real(8), parameter :: tblint = 10000.0
  real(8) , dimension(0:ntbl) :: tau_tbl
  real(8) , dimension(0:ntbl) :: exp_tbl
  real(8) , dimension(0:ntbl) :: tfn_tbl

  real(8), parameter :: pade = 0.278
  real(8) :: bpade = pade

end module rrlw_tbl

program test_rrlw_tbl
  use rrlw_tbl
  implicit none

  ! Assuming you want to test or demonstrate something with the module
  ! For example, let's print the bpade value to ensure it's initialized correctly
  
  print *, "Value of bpade:", bpade

  ! Here you can add more tests or usage examples of your rrlw_tbl module

end program test_rrlw_tbl