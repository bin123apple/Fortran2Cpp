program test_sin
  use, intrinsic :: iso_c_binding, only: c_float
  implicit none

  interface
      pure real(c_float) function sin_interf(x)
        import :: c_float
        real(c_float), intent(in) :: x
      end function sin_interf
  end interface

  procedure(sin_interf), pointer :: fptr => null()
  
  call assign_sin_to_pointer()
  call test_sin_function()

contains

  subroutine assign_sin_to_pointer()
    fptr => sin
  end subroutine assign_sin_to_pointer

  subroutine test_sin_function()
    real(c_float) :: result
    real(c_float), parameter :: input = 0.5_c_float ! Approx 30 degrees
    real(c_float) :: expected_value
    real(c_float), parameter :: tolerance = 0.0001_c_float

    result = fptr(input)
    expected_value = sin(input)

    print *, "Testing sin function with input: ", input
    if (abs(result - expected_value) > tolerance) then
      print *, "Test Failed. Expected: ", expected_value, " Got: ", result
    else
      print *, "Test Passed. Result: ", result
    end if
  end subroutine test_sin_function

end program test_sin