program add_numbers
  implicit none
  integer :: sum
  integer, parameter :: number1 = 5, number2 = 7

  sum = number1 + number2
  write(*,*) 'The sum is: ', sum
end program add_numbers