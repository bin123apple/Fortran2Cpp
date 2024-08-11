! test_mymod.f90
module mymod
  implicit none
  integer :: intnum
end module mymod

program testMyMod
  use mymod
  implicit none

  ! Test setting and getting intnum
  intnum = 5
  if (intnum == 5) then
    print *, "Test passed: intnum == 5"
  else
    print *, "Test failed: intnum /= 5"
  endif
end program testMyMod