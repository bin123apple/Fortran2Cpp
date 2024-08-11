program test_literalnonzero
  implicit none
  real :: result

  result = f(2.0)  ! Ensure the argument is a REAL by using 2.0 instead of 2
  if (result == 1.0) then
    print *, 'Test passed: f(2.0) = 1.0'
  else
    print *, 'Test failed: f(2.0) /= 1.0'
  end if

contains

  real function f(x)
    real, intent(in) :: x
    f = 1.0  ! Ensure consistency in using REAL literals
  end function f

end program test_literalnonzero