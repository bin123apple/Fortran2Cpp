module modphonon
  implicit none
  contains
    function square(x) result(res)
      real, intent(in) :: x
      real :: res

      res = x**2
    end function square
end module modphonon

program test_modphonon
  use modphonon
  implicit none

  real :: number, result

  ! Example usage of the square function
  number = 2.0
  result = square(number)
  print *, "Square of", number, "is", result

  number = -3.0
  result = square(number)
  print *, "Square of", number, "is", result

end program test_modphonon