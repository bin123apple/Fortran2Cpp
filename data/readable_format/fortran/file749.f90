module module_implicit_conversion
  implicit none
  double complex :: s = (1.0d0, 0.0d0)
end module module_implicit_conversion

program test_module_implicit_conversion
  use module_implicit_conversion
  implicit none

  double complex :: expected_s
  expected_s = (1.0d0, 0.0d0)

  if (s == expected_s) then
    print *, "Test passed: s is correctly initialized."
  else
    print *, "Test failed: s is not correctly initialized."
  end if
end program test_module_implicit_conversion