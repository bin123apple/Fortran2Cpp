! main.f90
program main
  implicit none
  ! Test variables initialization
  call test_variables()
contains
  subroutine test_variables()
    integer, parameter :: n = 2
    integer  :: a, b, c, d
    a = 0
    b = 0
    c = 0
    d = 0
    if (a == 0 .and. b == 0 .and. c == 0 .and. d == 0) then
      print *, "Test passed."
    else
      print *, "Test failed."
    endif
  end subroutine test_variables
end program main