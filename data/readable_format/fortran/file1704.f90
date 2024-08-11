program tminmaxval_test
  implicit none

  character(len=*), parameter :: b = "a"
  character(len=*), parameter :: e = "c"
  character(len=*), parameter :: s(3) = (/"a", "b", "c"/)

  if (minval(s) == b) then
    print *, "Minimum value test passed."
  else
    print *, "Minimum value test failed."
  end if

  if (maxval(s) == e) then
    print *, "Maximum value test passed."
  else
    print *, "Maximum value test failed."
  end if

end program tminmaxval_test