! my_program.f90
module my_module
  implicit none
contains
  function add_numbers(a, b)
    integer :: add_numbers
    integer, intent(in) :: a, b
    add_numbers = a + b
  end function add_numbers
end module my_module

program test_my_program
  use my_module
  implicit none
  
  integer :: result

  result = add_numbers(2, 3)
  if (result == 5) then
    print *, "Test passed with result = ", result
  else
    print *, "Test failed with result = ", result
  end if
end program test_my_program