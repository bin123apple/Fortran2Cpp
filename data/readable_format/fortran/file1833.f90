program factorial_program
  implicit none
  integer :: number
  integer :: result

  print *, 'Enter a number:'
  read *, number

  result = factorial(number)

  print *, 'The factorial of', number, 'is', result

contains

  recursive function factorial(n) result(fact)
    integer, intent(in) :: n
    integer :: fact

    if (n <= 1) then
      fact = 1
    else
      fact = n * factorial(n-1)
    endif
  end function factorial

end program factorial_program