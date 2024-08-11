program test_def_kinrea
  implicit none
  
  ! Definitions that were originally in the module
  integer, parameter :: ip = selected_int_kind(9)
  integer, parameter :: rp = kind(1.0d0)

  ! Test for integer kind
  if (ip == selected_int_kind(9)) then
    print *, "PASS: ip has the correct kind."
  else
    print *, "FAIL: ip does not have the correct kind."
  end if

  ! Test for real kind
  if (rp == kind(1.0d0)) then
    print *, "PASS: rp has the correct kind."
  else
    print *, "FAIL: rp does not have the correct kind."
  end if

end program test_def_kinrea