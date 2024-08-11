! real_precision_module.f90
module real_precision
  integer, parameter :: dp = selected_real_kind(15, 308)
end module real_precision

! test_real_precision.f90
program test_real_precision
  use real_precision
  implicit none
  real(dp) :: test_number
  test_number = 1.0_dp / 3.0_dp
  
  print *, "Testing double precision: ", test_number
  if (abs(test_number - 0.333333333333333_dp) < 1.0E-15_dp) then
    print *, "Test passed."
  else
    print *, "Test failed."
  endif
end program test_real_precision