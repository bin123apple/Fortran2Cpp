! square.f90
module math_operations
  implicit none
contains
  function square(x) result(res)
    implicit none
    real, intent(in) :: x
    real :: res
    res = x * x
  end function square
end module math_operations

program test
  use math_operations
  implicit none
  real :: number, result
  number = 4.0
  result = square(number)
  print *, "Square of", number, "is", result
end program test