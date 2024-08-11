module tanh_module
  implicit none
contains
  elemental function specific__tanh_r8(parm) result(res)
    real(kind=8), intent(in) :: parm
    real(kind=8) :: res

    res = tanh(parm)
  end function specific__tanh_r8
end module tanh_module

program test_specific_tanh_r8
  use tanh_module
  implicit none

  real(kind=8) :: input, expected, result

  ! Test Case 1
  input = 0.0
  expected = 0.0
  result = specific__tanh_r8(input)
  print *, "Input:", input, "Expected:", expected, "Result:", result

  ! Test Case 2
  input = 1.0
  expected = tanh(1.0)
  result = specific__tanh_r8(input)
  print *, "Input:", input, "Expected:", expected, "Result:", result

  ! Test Case 3
  input = -1.0
  expected = tanh(-1.0)
  result = specific__tanh_r8(input)
  print *, "Input:", input, "Expected:", expected, "Result:", result

  ! Add more test cases as needed

end program test_specific_tanh_r8