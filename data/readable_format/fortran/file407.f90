module functions
  implicit none
contains
  integer pure function double(x)
    integer, intent(in) :: x
    double = x * 2
  end function double
end module functions

program main
  use functions
  implicit none

  call testDoubleFunction()

contains
  subroutine testDoubleFunction()
    integer :: result
    result = double(10)
    if (result /= 20) then
      print *, "Test failed: double(10) should be 20."
    else
      print *, "Test passed: double(10) is 20."
    end if
  end subroutine testDoubleFunction

  ! You can add additional test subroutines here if needed

end program main