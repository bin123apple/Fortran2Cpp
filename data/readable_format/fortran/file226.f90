module c_kind_tests_2
  use, intrinsic :: iso_c_binding
  implicit none

  integer, parameter :: myF = c_float
  real(myF), bind(c) :: myCFloat = 1.0
  integer(myF), bind(c) :: myCInt = 42
  integer(c_double), bind(c) :: myCInt2 = 84

  integer, parameter :: myI = c_int
  real(myI) :: myReal = 2.0
  real(myI), bind(c) :: myCFloat2 = 3.0
  real(4), bind(c) :: myFloat = 4.0

contains
  subroutine test_variables
    print *, "Testing Fortran Variables"
    print *, "myCFloat:", myCFloat
    print *, "myCInt:", myCInt
    print *, "myCInt2:", myCInt2
    print *, "myReal:", myReal
    print *, "myCFloat2:", myCFloat2
    print *, "myFloat:", myFloat
    ! Add more tests and checks here as needed.
  end subroutine test_variables
end module c_kind_tests_2

program test
  use c_kind_tests_2
  call test_variables
end program test