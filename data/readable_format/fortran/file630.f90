program math_test
  implicit none

  print *, "Testing hypot and hypot3 functions"
  call test_hypot_functions()
  print *, "Testing complete."

contains

  real(8) function hypot(a, b)
    real(8), intent(in) :: a, b
    hypot = sqrt(a**2 + b**2)
  end function hypot

  real(8) function hypot3(a, b, c)
    real(8), intent(in) :: a, b, c
    hypot3 = sqrt(a**2 + b**2 + c**2)
  end function hypot3

  subroutine unit_assert_equal_within(testName, expected, actual, tolerance)
    character(len=*), intent(in) :: testName
    real(8), intent(in) :: expected, actual, tolerance

    if (abs(expected - actual) > tolerance) then
      print *, testName // " failed: Expected ", expected, ", got ", actual
    else
      print *, testName // " passed."
    endif
  end subroutine unit_assert_equal_within

  subroutine test_hypot_functions()
    real(8) :: r

    ! Test hypot function
    r = hypot(3.0d0, 4.0d0)
    call unit_assert_equal_within('hypot', 5.0d0, r, 1.0d-12)

    ! Test hypot3 function
    r = hypot3(3.0d0, 4.0d0, 0.0d0)
    call unit_assert_equal_within('hypot3', 5.0d0, r, 1.0d-12)
  end subroutine test_hypot_functions

end program math_test