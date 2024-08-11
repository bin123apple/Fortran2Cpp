! sum.f90
module sum_module
  implicit none
contains
  function add_numbers(a, b) result(sum)
    integer, intent(in) :: a, b
    integer :: sum

    sum = a + b
  end function add_numbers
end module sum_module

program test
  use sum_module
  implicit none

  write(*,*) 'Testing sum of 5 and 3: ', add_numbers(5, 3)
end program test