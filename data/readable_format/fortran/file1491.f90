module aot_extdouble_top_module
  implicit none
  private
  public :: xdble_k  ! Make xdble_k accessible outside the module
  integer, parameter :: xdble_k = selected_real_kind(18)
end module aot_extdouble_top_module

program test_aot_extdouble
  use aot_extdouble_top_module, only: xdble_k
  implicit none
  real(kind=xdble_k) :: test_value
  real(kind=xdble_k) :: tolerance
  real(kind=xdble_k) :: difference

  ! Test the precision of xdble_k by comparing a calculated value with an expected value
  test_value = 12345.6789012345678901_xdble_k
  tolerance = 0.0000000000000001_xdble_k
  difference = abs(test_value - 12345.6789012345678901_xdble_k)

  print *, "Testing precision of xdble_k kind:"
  print *, "Assigned value: ", test_value
  print *, "Difference from expected: ", difference

  if (difference <= tolerance) then
    print *, "Test PASSED: Precision is as expected."
  else
    print *, "Test FAILED: Precision difference is beyond tolerance."
  end if
end program test_aot_extdouble