program test_constants
  implicit none

  ! Define constants directly in the program
  integer, parameter :: long_string_size = 100000
  integer, parameter :: string_size = 1000
  integer, parameter :: short_string_size = 10

  ! Variables to hold the constants for testing
  integer :: test_long_string_size
  integer :: test_string_size
  integer :: test_short_string_size

  ! Assign the constants to the variables
  test_long_string_size = long_string_size
  test_string_size = string_size
  test_short_string_size = short_string_size

  ! Print the values to verify correctness
  print *, 'Long string size: ', test_long_string_size
  print *, 'String size: ', test_string_size
  print *, 'Short string size: ', test_short_string_size

  ! Check if the values are correct
  if (test_long_string_size /= 100000) then
    print *, 'Test failed: long_string_size'
  else if (test_string_size /= 1000) then
    print *, 'Test failed: string_size'
  else if (test_short_string_size /= 10) then
    print *, 'Test failed: short_string_size'
  else
    print *, 'All tests passed.'
  end if

end program test_constants