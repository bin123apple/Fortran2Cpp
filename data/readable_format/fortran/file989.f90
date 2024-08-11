module template
  use iso_fortran_env, only : real32, int64
  implicit none

  private
  public :: test, templ

contains

  pure integer (int64) function templ(n)
    integer (int64), intent(in) :: n
    templ = n * n
  end function templ

  subroutine test(n)
    integer (int64), intent(inout) :: n
    n = n + 1
    write(*,*) "hello module"
  end subroutine test

end module template

program test_template
  use iso_fortran_env, only : int64
  use template
  implicit none

  integer(int64) :: n
  integer(int64) :: result

  ! Test templ function
  n = 5
  result = templ(n)
  if (result /= 25_int64) then
    write(*,*) "Test templ failed: Expected 25, Got ", result
    error stop
  end if

  ! Test test subroutine
  n = 10
  call test(n)
  if (n /= 11_int64) then
    write(*,*) "Test test failed: Expected 11, Got ", n
    error stop
  end if

  write(*,*) "All tests passed."
end program test_template