program factorial_calculator
  implicit none
  integer :: number
  integer :: result

  print *, 'Enter a positive integer:'
  read *, number

  if (number < 0) then
     print *, 'Factorial of a negative number doesn't exist.'
  else
     result = factorial(number)
     print *, 'Factorial of', number, 'is', result
  endif
end program factorial_calculator

integer function factorial(n)
  integer, intent(in) :: n
  integer :: i
  factorial = 1
  do i = 1, n
     factorial = factorial * i
  end do
end function factorial