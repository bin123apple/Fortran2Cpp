module math_utils
  implicit none
contains
  function add(a, b) result(c)
    integer, intent(in) :: a, b
    integer :: c

    c = a + b
  end function add
end module math_utils

program test_add_function
  use math_utils
  implicit none

  integer :: result

  result = add(1, 2)
  print *, 'The result of adding 1 and 2 is: ', result

end program test_add_function