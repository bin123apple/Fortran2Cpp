program testDatadim
  implicit none
  integer :: a(10), i, errors
  data (a(i), i = 1, 10) / 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 /
  errors = 0
  
  do i = 1, 10
    if (a(i) /= i-1) then
      print *, "Test failed for element: ", i, "Expected: ", i-1, "Got: ", a(i)
      errors = errors + 1
    endif
  end do
  
  if (errors == 0) then
    print *, "All tests passed."
  else
    print *, errors, " tests failed."
  endif
end program testDatadim