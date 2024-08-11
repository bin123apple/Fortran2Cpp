program test
  implicit none
  integer, dimension(1:10) :: arr
  integer :: i

  ! Initialize array
  do i = 1, 10
     arr(i) = i
  end do

  !$acc data copy(arr)
  !$acc parallel loop
  do i = 1, 10
     arr(i) = arr(i) + 1
  end do
  !$acc end data

  ! Printing for debugging (not part of unit tests)
  do i = 1, 10
     print *, 'arr(', i, ') = ', arr(i)
  end do

end program test