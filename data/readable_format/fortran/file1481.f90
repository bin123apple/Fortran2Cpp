module specific_atan_mod
  implicit none
  contains
    elemental function specific__atan_r4 (parm)
      real (kind=4), intent (in) :: parm
      real (kind=4) :: specific__atan_r4
      specific__atan_r4 = atan (parm)
    end function specific__atan_r4
end module specific_atan_mod

program test_specific_atan_r4
  use specific_atan_mod
  implicit none
  real(kind=4) :: result
  real(kind=4), parameter :: pi = 3.14159265_4

  ! Test 1: atan(1) should be pi/4
  result = specific__atan_r4(1.0_4)
  print *, "Test 1: atan(1) = ", result
  if (abs(result - pi/4) < 1.0E-6_4) then
     print *, "Passed Test 1."
  else
     print *, "Failed Test 1."
  endif

  ! Additional tests can be added in a similar manner
end program test_specific_atan_r4