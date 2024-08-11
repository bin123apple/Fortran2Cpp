! -- mod_globals.f90 --
module mod_globals
  implicit none
  character(len=*), parameter :: EvsInit = "FF", InEvsInit = "done"
  character(len=10) :: Evs = EvsInit, InEvs = InEvsInit
  integer :: Nf_FF
end module mod_globals

! -- SetFFNS.f90 --
subroutine SetFFNS(nfl)
  use mod_globals
  implicit none
  integer :: nfl
  Evs = "FF"
  Nf_FF = nfl
  InEvs = "done"
end subroutine SetFFNS

! -- test_SetFFNS.f90 --
program test_SetFFNS
  use mod_globals
  implicit none
  integer :: testNfl

  testNfl = 5
  call SetFFNS(testNfl)

  if (Evs == EvsInit .and. Nf_FF == testNfl .and. InEvs == InEvsInit) then
    print *, "Test passed."
  else
    print *, "Test failed."
  end if
end program test_SetFFNS