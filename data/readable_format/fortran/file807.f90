! combined_sum.f90
program sum_array
  implicit none
  integer, parameter :: n = 5
  integer :: arr(n)
  integer :: sum

  ! Initialize the array
  arr = (/1, 2, 3, 4, 5/)

  ! Call the calculate_sum function
  sum = calculate_sum(arr, n)

  ! Print the result
  print *, "Sum = ", sum

contains

  ! The calculate_sum function is defined within the same file
  function calculate_sum(arr, n) result(sum)
    integer, intent(in) :: n
    integer, intent(in) :: arr(n)
    integer :: sum, i

    sum = 0
    do i = 1, n
       sum = sum + arr(i)
    end do
  end function calculate_sum

end program sum_array