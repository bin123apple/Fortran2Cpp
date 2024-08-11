program test_slice
  implicit none
  
  real (kind = 8), dimension(2, 2, 2) :: x
  real (kind = 8) :: min, max

  x = 1.0
  if (minval(x(1, 1:2, 1:1)) .ne. 1.0) print *, "Test 1 Failed"
  if (maxval(x(1, 1:2, 1:1)) .ne. 1.0) print *, "Test 2 Failed"
  if (any (shape(x(1, 1:2, 1:1)) .ne. (/2, 1/))) print *, "Test 3 Failed"

  if (any (shape(x(1, 1:2, 1)) .ne. (/2/))) print *, "Test 4 Failed"
  if (any (shape(x(1:1, 1:2, 1:1)) .ne. (/1, 2, 1/))) print *, "Test 5 Failed"
  
  print *, "Tests completed"
  
end program test_slice