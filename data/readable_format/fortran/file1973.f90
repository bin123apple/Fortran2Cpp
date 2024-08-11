module array_functions
  implicit none
contains
  integer function f(x)
    integer, dimension(:), intent(in) :: x
    f = sum(x)
  end function f
end module array_functions

program array_function_1
  use array_functions
  integer :: a(5), b, l, u

  a = (/ 1, 2, 3, 4, 5 /)
  l = 4
  u = 2

  b = f(a(l:u:-1) - 2) ! Corrected to ensure consistent behavior
  print *, "Result in main program:", b
end program array_function_1