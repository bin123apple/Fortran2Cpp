module my_functions
  implicit none
contains
  integer function f1(x, y)
    integer, intent(in) :: x, y
    f1 = x + y  ! Example operation
  end function f1

  complex function f2(x)
    complex, intent(in) :: x
    f2 = x  ! Example operation; originally had allocatable which is not shown here
  end function f2

  real function f2b(x, y)
    real, intent(in) :: x, y
    f2b = x + y  ! Example operation
  end function f2b
end module my_functions

program test
  use my_functions
  implicit none

  ! Test variables
  integer :: int_x = 1, int_y = 2
  real :: real_result
  complex :: complex_result
  complex :: complex_x
  
  complex_x = (1.1, 2.2)

  ! Adjusted to directly call and test functions/subroutines
  print *, "Testing f1:", f1(int_x, int_y)
  complex_result = f2(complex_x)
  print *, "Testing f2:", complex_result
  real_result = f2b(1.1, 2.2)
  print *, "Testing f2b:", real_result

end program test