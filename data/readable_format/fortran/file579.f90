! sum_array_test.f90
program sum_array_test
  implicit none
  integer, dimension(3) :: test_array = [10, 20, 30]
  integer :: expected_sum, actual_sum

  expected_sum = 60
  actual_sum = sum_array(test_array, 3)

  if (actual_sum == expected_sum) then
    print *, "Test passed."
  else
    print *, "Test failed."
  end if

contains

  function sum_array(arr, n) result(total)
    integer, intent(in) :: n
    integer, dimension(n), intent(in) :: arr
    integer :: total, i

    total = 0
    do i = 1, n
      total = total + arr(i)
    end do
  end function sum_array

end program sum_array_test