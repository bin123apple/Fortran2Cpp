program test
  implicit none
  integer :: i, j
  
  do i = 1, 10
    j = i
  end do
  
  j = 20
  
  do i = 1, 10
    if ( j < 15 ) then
      j = i
      print*, 'HERE'
    endif
  end do
  
  print*, 'Final value of j:', j
end program test