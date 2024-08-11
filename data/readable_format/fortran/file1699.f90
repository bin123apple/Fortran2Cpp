program test
  implicit none
  integer :: i
  integer, dimension(10) :: d

  d = 0
  do concurrent (i=1:5)
     d(i) = i
  end do

  print *, d
end program test