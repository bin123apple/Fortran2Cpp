module specific_functions_mod
  implicit none
contains
  ! Definition of the specific__log10_r4 function
  elemental function specific__log10_r4 (parm) result(log10_result)
    real(kind=4), intent(in) :: parm
    real(kind=4) :: log10_result
  
    log10_result = log10(parm)
  end function specific__log10_r4
end module specific_functions_mod

program test_log10
  use specific_functions_mod
  implicit none
  real(kind=4) :: result
  real(kind=4), parameter :: epsilon = 1.0E-5 ! Tolerance for floating-point comparison

  ! Test 1
  result = specific__log10_r4(10.0)
  if (abs(result - 1.0) > epsilon) then
    print *, "Test 1 failed: Expected 1.0, got", result
  else
    print *, "Test 1 passed."
  end if

  ! Test 2
  result = specific__log10_r4(100.0)
  if (abs(result - 2.0) > epsilon) then
    print *, "Test 2 failed: Expected 2.0, got", result
  else
    print *, "Test 2 passed."
  end if

end program test_log10