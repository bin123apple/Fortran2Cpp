module modE
  implicit none
contains
  function square(x) result(res)
    real, intent(in) :: x
    real :: res
    res = x**2
  end function square
end module modE

program testSquare
  use modE
  implicit none
  real :: inputValue
  real :: result

  ! Prompt the user for a number
  print *, "Enter a number to square: "
  read *, inputValue

  ! Use the square function from modE
  result = square(inputValue)

  ! Display the result
  print *, "The square of ", inputValue, " is ", result
end program testSquare