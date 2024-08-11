module test_module
contains
  subroutine bar(expr)
    character(*), intent(in) :: expr
    character(*), parameter  :: chrs = '-+.0123456789eEdD'

    if (index(chrs, expr) /= 1) call abort()
  end subroutine bar

  integer function foo(expr)
    character(*), intent(in) :: expr
    character(*), parameter  :: chrs = '-+.0123456789eEdD'
    foo = index(chrs, expr)
  end function foo
end module test_module

program test_fortran
  use test_module
  implicit none
  character(*), parameter :: chrs = '-+.0123456789eEdD'
  character(*), parameter :: expr = '-+.0123456789eEdD'

  call test_index()
  call test_foo()
  call bar(expr)

  print *, 'All Fortran tests passed.'

contains
  subroutine test_index()
    if (index(chrs, expr) /= 1) call abort
  end subroutine test_index

  subroutine test_foo()
    if (foo(expr) /= 1) call abort
  end subroutine test_foo
end program test_fortran