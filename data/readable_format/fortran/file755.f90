program test_f_function
  implicit none
  real :: result
  real, parameter :: expected = 0.8414709848 ! Expected result for sin(1)
  real, parameter :: tolerance = 1.0E-7

  result = f(1.0)
  print *, "Testing f(1.0)..."

  if (abs(result - expected) < tolerance) then
    print *, "Test passed."
  else
    print *, "Test failed."
    print *, "Expected:", expected
    print *, "Got:", result
  end if

contains

  pure function f(x) result(func_result)
    real, value :: x
    real :: func_result
    func_result = sin(x)
  end function f

end program test_f_function