program test_x
  implicit none
  real(kind=16) :: x, expected_x
  x = 1.0_16 + 2.0_16**(-105)
  expected_x = 1.0_16 + 2.0_16**(-105)

  if (abs(x - expected_x) < 1.0_16**(-104)) then
     print *, "Test passed."
  else
     print *, "Test failed."
  end if
end program test_x