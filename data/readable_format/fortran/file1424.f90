program mainProgram
  implicit none
  integer :: inputNumber, result

  ! Ask for a number
  print *, "Enter a number to calculate factorial: "
  read *, inputNumber

  ! Calculate factorial using the internal function
  result = factorial(inputNumber)

  ! Print the result
  print *, "The factorial of ", inputNumber, " is ", result

contains

  ! Internal function to calculate factorial
  function factorial(n) result(fact)
    integer, intent(in) :: n
    integer :: fact, i

    fact = 1
    do i = 1, n
      fact = fact * i
    end do
  end function factorial

end program mainProgram