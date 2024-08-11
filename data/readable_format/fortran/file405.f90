program testProgram
  implicit none
  integer :: result

  ! Test the doubleValue function
  result = doubleValue(5)
  if (result == 10) then
    print *, "Fortran Test Passed: The result is: ", result
  else
    print *, "Fortran Test Failed."
  end if

contains

  ! Function to double the input value
  function doubleValue(x) result(res)
    implicit none
    integer, intent(in) :: x
    integer :: res
    
    res = x * 2
  end function doubleValue

end program testProgram