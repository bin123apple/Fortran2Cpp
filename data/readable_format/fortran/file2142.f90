program test_operations
  use, intrinsic :: iso_c_binding, only : c_int128_t, c_float128
  implicit none

  integer(c_int128_t) :: int128_var
  real(c_float128) :: float128_var
  complex(c_float128) :: float128_complex_var

  ! Initialize variables
  int128_var = 42_c_int128_t
  float128_var = 3.141592653589793238462643383279502884197_c_float128
  float128_complex_var = (1.0_c_float128, -1.0_c_float128)

  ! Operations
  int128_var = int128_var + 10
  float128_var = float128_var * 2.0_c_float128
  float128_complex_var = float128_complex_var + cmplx(0.0_c_float128, 2.0_c_float128)

  ! Output the results
  print *, "Int128 Var: ", int128_var
  print *, "Float128 Var: ", float128_var
  print *, "Float128 Complex Var: ", real(float128_complex_var), aimag(float128_complex_var)
end program test_operations