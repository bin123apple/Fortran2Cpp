program test
  implicit none
  integer :: a
  a = 1
  call test_a(a)
contains
  subroutine test_a(a)
    integer, intent(in) :: a
    if (a == 1) then
      print *, "Test Passed: a = 1"
    else
      print *, "Test Failed: a is not 1"
    end if
  end subroutine test_a
end program test