module avg_module
  implicit none
contains
  function avg(a) result(average)
    integer, intent(in) :: a(:)
    integer :: average
    average = sum(a) / size(a)
  end function avg
end module avg_module

program test_avg
  use avg_module
  implicit none
  integer :: result
  integer, dimension(5) :: test_data = [1, 2, 3, 4, 5]

  result = avg(test_data)
  print *, "The average is: ", result
end program test_avg