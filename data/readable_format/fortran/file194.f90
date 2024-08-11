module specific_functions
  implicit none
contains
  elemental function specific__aint_r4(parm) result(res)
    real(kind=4), intent(in) :: parm
    real(kind=4) :: res

    res = aint(parm)
  end function specific__aint_r4
end module specific_functions

program test_specific_aint_r4
  use specific_functions
  implicit none
  real(kind=4) :: result

  ! Test positive value
  result = specific__aint_r4(123.456)
  call assert_equals(123.0, result, 'Test positive value')

  ! Test negative value
  result = specific__aint_r4(-123.456)
  call assert_equals(-123.0, result, 'Test negative value')

  ! Test zero
  result = specific__aint_r4(0.0)
  call assert_equals(0.0, result, 'Test zero')

  ! Test very small positive value
  result = specific__aint_r4(0.0001)
  call assert_equals(0.0, result, 'Test very small positive value')

  ! Test very small negative value
  result = specific__aint_r4(-0.0001)
  call assert_equals(0.0, result, 'Test very small negative value')

contains

  subroutine assert_equals(expected, actual, message)
    real(kind=4), intent(in) :: expected, actual
    character(*), intent(in) :: message
    if (expected /= actual) then
      print *, trim(message), ": Failed - Expected:", expected, "Actual:", actual
    else
      print *, trim(message), ": Passed"
    end if
  end subroutine assert_equals

end program test_specific_aint_r4