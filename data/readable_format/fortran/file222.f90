! Assuming the Fortran module Foo_mod and its subroutine runFoo4C
! are defined in a separate file as provided in your original code.

module Foo_mod
  use, intrinsic :: iso_c_binding
  implicit none

contains
  subroutine runFoo4C(ndim) bind(C, name="runFoo")
    use, intrinsic :: iso_c_binding
    implicit none
    integer(c_int32_t), intent(in) :: ndim
    print *, "Running runFoo with ndim =", ndim
  end subroutine runFoo4C
end module Foo_mod

! Test program
program test_runFoo
  use, intrinsic :: iso_c_binding
  use Foo_mod
  implicit none
  integer(c_int32_t) :: test_ndim

  test_ndim = 5
  call runFoo4C(test_ndim)
end program test_runFoo