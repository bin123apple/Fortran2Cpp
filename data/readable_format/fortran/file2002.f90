! sum_array.f90
module sum_module
  implicit none
contains
  function sumArray(arr) result(total)
    integer, intent(in) :: arr(:)
    integer :: total
    total = sum(arr)
  end function sumArray
end module sum_module

program test
  use sum_module
  implicit none
  integer, dimension(5) :: testArray = [1, 2, 3, 4, 5]
  print *, sumArray(testArray)
end program test