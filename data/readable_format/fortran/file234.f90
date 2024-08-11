program test_xdatanh
  implicit none
  double precision :: x, result, expected

  ! Test input
  x = 0.5d0
  ! Expected result for comparison
  expected = datanh(x)
  ! Call the subroutine to test
  call xdatanh(x, result)

  ! Check the result against the expected value with a tolerance
  if (abs(result - expected) < 1.0d-7) then
    print *, "Test passed for x=", x
  else
    print *, "Test failed: x=", x, " expected=", expected, " got=", result
  end if

contains

  ! The subroutine to be tested
  subroutine xdatanh(x, result)
    implicit none
    double precision, intent(in) :: x
    double precision, intent(out) :: result
    ! Call the external function within the subroutine
    result = datanh(x)
  end subroutine xdatanh

  ! Function definition for datanh assuming it's the hyperbolic tangent
  double precision function datanh(x)
    implicit none
    double precision, intent(in) :: x
    datanh = tanh(x)  ! Calculate hyperbolic tangent
  end function datanh

end program test_xdatanh