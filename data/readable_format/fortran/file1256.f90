program sum_array
  implicit none
  integer, parameter :: n = 5
  integer :: i, total
  integer, dimension(n) :: array

  ! Initialize the array
  do i = 1, n
     array(i) = i
  end do

  ! Calculate the sum of the array elements
  total = 0
  do i = 1, n
     total = total + array(i)
  end do

  print *, "Sum of array elements is: ", total
end program sum_array