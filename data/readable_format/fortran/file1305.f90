program p
  integer :: i, sum
  sum = 0
  !$acc loop
  do concurrent (i=1:3)
     sum = sum + i
  end do
  print *, sum
end program p