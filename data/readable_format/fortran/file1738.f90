module precision
  implicit none
  private
  public :: int1, int2, int4, int8
  public :: real4, real8, real16
  public :: ik, rk
  integer, parameter :: int1 = selected_int_kind(1)
  integer, parameter :: int2 = selected_int_kind(2)
  integer, parameter :: int4 = selected_int_kind(8)
  integer, parameter :: int8 = selected_int_kind(16)
  integer, parameter :: real4 = selected_real_kind(6)
  integer, parameter :: real8 = selected_real_kind(15)
  integer, parameter :: real16 = selected_real_kind(32)
  integer, parameter :: ik = int4
  integer, parameter :: rk = real8
end module precision

program testPrecision
  use precision
  implicit none

  ! Test variables
  integer(int1) :: testInt1
  integer(int2) :: testInt2
  integer(int4) :: testInt4
  integer(int8) :: testInt8
  real(real4) :: testReal4
  real(real8) :: testReal8
  real(real16) :: testReal16

  ! Output kinds
  print *, "Testing integer kinds..."
  print *, "int1 kind: ", kind(testInt1)
  print *, "int2 kind: ", kind(testInt2)
  print *, "int4 kind: ", kind(testInt4)
  print *, "int8 kind: ", kind(testInt8)

  print *, "Testing real kinds..."
  print *, "real4 kind: ", kind(testReal4)
  print *, "real8 kind: ", kind(testReal8)
  print *, "real16 kind: ", kind(testReal16)

end program testPrecision