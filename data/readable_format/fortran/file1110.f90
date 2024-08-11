module precision_config
  implicit none
  integer, parameter :: wp = selected_real_kind(15, 307)
  real(wp), parameter :: pi = 4.0_wp * atan(1.0_wp)
  real(wp), parameter :: f_actual = -9.02462E-6_wp
end module precision_config

module functions
  use precision_config
  implicit none
contains
  function f1(x)
    real(wp), intent(in) :: x
    real(wp) :: f1
    f1 = sin(x) / (1.0_wp + 2.0_wp * exp(2.0_wp * x))
  end function f1

  function f2(x)
    real(wp), intent(in) :: x
    real(wp) :: f2
    f2 = (x**2 - 3.0_wp * x) / ((x**2 + 1.0_wp) * (x**2 + 2.0_wp))
  end function f2

  function f(x, y)
    real(wp), intent(in) :: x, y
    real(wp) :: f
    f = f2(x) * f1(y)
  end function f
end module functions

program test_functions
  use functions
  implicit none
  real(wp) :: x, y
  real(wp) :: tolerance = 1.0E-6_wp
  real(wp) :: result

  ! Test f1
  x = 0.5_wp
  result = f1(x)
  if (abs(result - sin(x) / (1.0_wp + 2.0_wp * exp(2.0_wp * x))) > tolerance) then
    print *, "Test f1 FAILED"
  else
    print *, "Test f1 PASSED"
  end if

  ! Test f2
  x = 1.0_wp
  result = f2(x)
  if (abs(result - ((x**2 - 3.0_wp * x) / ((x**2 + 1.0_wp) * (x**2 + 2.0_wp)))) > tolerance) then
    print *, "Test f2 FAILED"
  else
    print *, "Test f2 PASSED"
  end if

  ! Test f
  x = 0.5_wp
  y = 0.7_wp
  result = f(x, y)
  if (abs(result - f2(x) * f1(y)) > tolerance) then
    print *, "Test f FAILED"
  else
    print *, "Test f PASSED"
  end if

end program test_functions