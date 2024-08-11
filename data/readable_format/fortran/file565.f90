program main
  integer :: x
  integer :: y
  common /blk/ y
  y = 5
  x = y
  print *, 'x:', x, 'y:', y
end program