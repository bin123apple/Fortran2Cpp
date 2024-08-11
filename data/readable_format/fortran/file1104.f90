program test_main
  implicit none
  integer :: i
  real :: array(123), val
  logical :: test_passed

  test_passed = .true.

  ! Initialize the array with random numbers using a simple DO loop
  do i = 1, 123
     call random_number(val)
     array(i) = val
     ! Check each value to ensure it is within the expected range
     if (array(i) < 0.0 .or. array(i) > 1.0) then
        test_passed = .false.
        exit ! Exit the loop as soon as a value out of range is found
     end if
  end do

  ! Output the test result
  if (test_passed) then
     print *, "Test passed: All values are within the range [0.0, 1.0]."
  else
     print *, "Test failed: Some values are out of the expected range."
  end if
end program test_main