program add_numbers
  implicit none
  real :: number1, number2, sum

  print *, 'Enter two numbers:'
  read(*, *) number1, number2

  sum = number1 + number2

  print *, 'The sum is:', sum
end program add_numbers