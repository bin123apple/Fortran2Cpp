module foo
  implicit none
  integer(kind=4), parameter :: pi = 3
end module foo

program test
  use foo
  implicit none
  print *, "Testing the value of pi..."
  if (pi == 3) then
    print *, "Test passed. pi is 3."
  else
    print *, "Test failed. pi is not 3."
  end if
end program test