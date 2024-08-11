program test
  implicit none
  real :: a = 1.23
  real, parameter :: expected_value = 1.23
  logical :: test_passed

  test_passed = abs(a - expected_value) < 0.0001
  if (test_passed) then
    print *, "Test passed."
  else
    print *, "Test failed."
  end if
end program test