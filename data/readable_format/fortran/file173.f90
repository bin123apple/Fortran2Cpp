module config
  implicit none
  private

  integer, parameter :: sp = selected_real_kind(6)
  integer, parameter :: dp = selected_real_kind(15)
  integer, parameter :: ep = selected_real_kind(18)
  integer, parameter :: qp = selected_real_kind(30)
  integer, parameter :: wp = sp

  public wp, disp_wp

contains
  subroutine disp_wp
    write(*,*) wp
  end subroutine disp_wp
end module config

program testConfig
  use config
  implicit none

  call disp_wp

  ! Assuming we know the expected kind value for wp
  ! For example, if we know sp is kind=4 on our system (this is just an example)
  ! Note: Actual verification logic might differ based on the compiler and system
  if (wp == 4) then
    print *, "Test passed."
  else
    print *, "Test failed."
  endif
end program testConfig