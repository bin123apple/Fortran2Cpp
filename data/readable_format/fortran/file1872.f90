! Define a module for the square function
module square_module
  implicit none
contains
  ! Define the square function
  function square(x) result(res)
    real, intent(in) :: x
    real :: res
    res = x * x
  end function square
end module square_module

! Main program to test the square function
program test_square
  use square_module
  implicit none
  real :: x, y

  ! Test the square function
  x = 4.0
  y = square(x)
  print *, "Testing square function with x = ", x
  if (y == 16.0) then
    print *, "Test passed."
  else
    print *, "Test failed. Expected 16, got ", y
  end if
end program test_square