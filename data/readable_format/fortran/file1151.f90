module test_utils
  implicit none
contains
  subroutine test_assert(s, i1, i2, success)
    implicit none
    integer, intent(in) :: i1, i2
    integer, intent(inout) :: success
    character(*), intent(in) :: s
    if (i1 .ne. i2) then
      print *, s, ": expected ", i2, " but was ", i1
      success = 0
    endif
  end subroutine test_assert
end module test_utils

module functions
  implicit none
  contains
    function f(x) result(res)
      integer, intent(in) :: x
      integer :: res
      integer, save :: a = 0
      a = a + x
      res = a
    end function f
end module functions

program test
  use test_utils
  use functions
  implicit none
  integer :: success

  success = 1

  call test_f(success)

  if (success == 1) then
    print *, "All tests passed."
  else
    print *, "Some tests failed."
  endif

contains
  subroutine test_f(success)
    use functions
    implicit none
    integer, intent(inout) :: success
    call test_assert("f()", f(3), 3, success)
    call test_assert("f()", f(4), 7, success)
    call test_assert("f()", f(2), 9, success)
    ! Resetting the state is tricky since Fortran functions do not have a clear way to reset static variables without additional mechanisms
  end subroutine test_f
end program test