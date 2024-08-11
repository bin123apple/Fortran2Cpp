! test_type_param_int.f90
module type_param_int
  implicit none
  integer(8) :: i
end module type_param_int

program test_type_param_int
  use type_param_int
  implicit none
  logical :: all_tests_passed = .true.

  ! Initialize the integer and test if it holds the correct value
  i = 42
  if (i /= 42) then
    print *, "Test failed: i should be 42, but it is ", i
    all_tests_passed = .false.
  end if

  ! Final result
  if (all_tests_passed) then
    print *, "All tests passed."
  else
    print *, "Some tests failed."
  end if
end program test_type_param_int