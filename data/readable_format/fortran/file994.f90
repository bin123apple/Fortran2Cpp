module olbfgs_module
  use iso_c_binding
  implicit none

  private

  public :: dolbfgs
  public :: solbfgs
  
contains

  ! Double precision version
  function dolbfgs(a, b) result(res)
    real(c_double), intent(in) :: a, b
    real(c_double) :: res
    res = a + b
  end function dolbfgs

  ! Single precision version
  function solbfgs(a, b) result(res)
    real(c_float), intent(in) :: a, b
    real(c_float) :: res
    res = a + b
  end function solbfgs

end module olbfgs_module

program test_olbfgs
  use olbfgs_module
  use iso_c_binding
  implicit none

  real(c_double) :: result_d
  real(c_float)  :: result_s

  ! Testing the double precision function
  result_d = dolbfgs(1.0d0, 2.0d0)
  print *, "Result (double): ", result_d

  ! Testing the single precision function
  result_s = solbfgs(1.0, 2.0)
  print *, "Result (single): ", result_s

end program test_olbfgs