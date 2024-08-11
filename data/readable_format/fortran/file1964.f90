program sum_array
  implicit none
  integer :: i, sum, N
  integer, allocatable :: arr(:)
  N = 5
  allocate(arr(N))
  sum = 0

  ! Initialize the array
  do i=1, N
     arr(i) = i
  end do

  ! Calculate the sum
  do i=1, N
     sum = sum + arr(i)
  end do

  print *, "Sum = ", sum

end program sum_array