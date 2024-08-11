! test_foo.f90
module test_mod
  implicit none
contains
  pure subroutine foo()
    error stop "failed"
  end subroutine foo
end module test_mod

program test_foo
  use test_mod
  implicit none

  call foo()

end program test_foo