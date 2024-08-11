module complexity
contains
  real function g(x, y)
    real :: x, y
    g = (x*x*x*x*x*x + y*y*y*y)
  end function g
end module complexity

program test_complexity
  use complexity
  implicit none

  real :: result

  result = g(2.0, 3.0)
  print *, "Result of g(2.0, 3.0): ", result
  if (abs(result - 67.0) < 0.001) then
    print *, "Test Passed."
  else
    print *, "Test Failed."
  end if
end program test_complexity