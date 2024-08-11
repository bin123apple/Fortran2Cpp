module templateModule
  implicit none
  
  private
  public :: Sub1, Fun1

contains

  subroutine Sub1(par1, par2, par3)
    integer, intent(in) :: par1
    real, intent(inout) :: par2
    integer, intent(out) :: par3
    ! Example implementation
    par2 = par2 + 1.0
    par3 = 2
  end subroutine Sub1

  real function Fun1()
    Fun1 = 10.0
  end function Fun1

end module templateModule

program testTemplateModule
  use templateModule
  implicit none

  real :: testValue1
  integer :: testValue2, testValue3

  ! Test Fun1
  testValue1 = Fun1()
  print *, "Fun1 result: ", testValue1
  if (testValue1 == 10.0) then
    print *, "Fun1 test passed."
  else
    print *, "Fun1 test failed."
  endif

  ! Test Sub1
  testValue1 = 5.0
  call Sub1(1, testValue1, testValue3)
  print *, "Sub1 results: ", testValue1, testValue3
  if (testValue1 == 6.0 .and. testValue3 == 2) then
    print *, "Sub1 test passed."
  else
    print *, "Sub1 test failed."
  endif

end program testTemplateModule