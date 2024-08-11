! combined_type_param_real.f90
module type_param_real
  implicit none
  integer, parameter :: rk = kind(1.2)
  real(kind=rk) :: example_real = 0.0
end module type_param_real

program test_type_param_real
  use type_param_real
  implicit none

  example_real = 1.2
  print *, "Testing type_param_real module with example_real = ", example_real
  if (example_real == 1.2_rk) then
    print *, "Test passed."
  else
    print *, "Test failed."
  end if
end program test_type_param_real