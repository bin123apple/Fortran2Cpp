module foo_mod
  implicit none
  real :: a = 0.0
end module foo_mod

program test_foo
  use foo_mod
  a = 42.0
  if (a /= 42.0) then
    print *, "Test failed: The value of a is not 42"
  else
    print *, "Test passed: The value of a is 42"
  end if
end program test_foo