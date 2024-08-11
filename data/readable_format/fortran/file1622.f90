module mymodule
  implicit none
contains
  function doubleNumber(x)
    real, intent(in) :: x
    real :: doubleNumber
    
    doubleNumber = x * 2.0
  end function doubleNumber
end module mymodule

program testDoubleNumber
  use mymodule
  implicit none
  
  real :: result
  
  result = doubleNumber(5.0)
  if (result == 10.0) then
    print *, "Fortran Test Passed: Result = ", result
  else
    print *, "Fortran Test Failed"
  endif
end program testDoubleNumber