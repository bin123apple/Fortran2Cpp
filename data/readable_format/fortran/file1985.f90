module config
  implicit none
  private

  integer, parameter :: sp = selected_real_kind(6)
  integer, parameter :: dp = selected_real_kind(15)
  integer, parameter :: ep = selected_real_kind(18)
  integer, parameter :: qp = selected_real_kind(30)
  integer, parameter :: wp = dp

  public :: wp, disp_wp

contains

  subroutine disp_wp
    write(*,*) 'Precision kind of wp: ', wp
  end subroutine disp_wp

end module config

program test_config
  use config
  implicit none

  call disp_wp()
end program test_config