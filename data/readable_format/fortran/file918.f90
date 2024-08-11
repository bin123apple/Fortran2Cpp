program test_constants
  ! Using selected_real_kind to define double precision
  integer, parameter :: dp = selected_real_kind(15, 307)
  real(kind=dp), parameter :: PI = 3.1415926535898_dp

  real(kind=dp) :: test_pi
  real(kind=dp), parameter :: expected_pi = 3.1415926535898_dp

  test_pi = PI

  ! Test the value of PI
  if (abs(test_pi - expected_pi) > 1.0E-12_dp) then
    print *, "Test Failed: PI does not match the expected value."
  else
    print *, "Test Passed: PI matches the expected value."
  end if

end program test_constants