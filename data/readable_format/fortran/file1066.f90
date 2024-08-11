program test_sum
  implicit none
  integer :: output, expected_output

  ! Call the calculate_sum function and store the result
  output = calculate_sum(10)
  expected_output = 55

  ! Simple test to check if the calculate_sum function works as expected
  if (output == expected_output) then
    print *, "Test passed. Sum is: ", output
  else
    print *, "Test failed. Expected: ", expected_output, " Got: ", output
  end if

contains

  ! Function to calculate the sum of integers from 1 to n
  function calculate_sum(n) result(sum)
    implicit none
    integer, intent(in) :: n
    integer :: sum, i

    sum = 0
    do i = 1, n
      sum = sum + i
    end do
  end function calculate_sum

end program test_sum