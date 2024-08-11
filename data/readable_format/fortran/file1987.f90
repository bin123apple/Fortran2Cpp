module data_gllmesh
  implicit none
  ! Assuming dp kind parameter for double precision
  integer, parameter :: dp = selected_real_kind(15, 307)
  public
  real(kind=dp), dimension(:,:,:), allocatable :: sgll, zgll
  real(kind=dp), dimension(:,:,:), allocatable :: sgll_fluid, zgll_fluid
  real(kind=dp), dimension(:,:,:), allocatable :: sgll_solid, zgll_solid

  real(kind=dp) :: hmin_glob, hmax_glob
  real(kind=dp) :: min_distance_dim
  real(kind=dp) :: min_distance_nondim

  real(kind=dp) :: char_time_max
  integer :: char_time_max_globel
  real(kind=dp) :: char_time_max_rad, char_time_max_theta
  real(kind=dp) :: char_time_min
  integer :: char_time_min_globel
  real(kind=dp) :: char_time_min_rad, char_time_min_theta
end module data_gllmesh

program test_data_gllmesh
  use data_gllmesh
  implicit none

  integer :: x, y, z
  x = 2; y = 3; z = 4

  ! Allocate and initialize
  allocate(sgll(x,y,z))
  allocate(zgll(x,y,z))
  sgll = 1.0_dp
  zgll = 2.0_dp

  ! Check values
  if (all(sgll == 1.0_dp) .and. all(zgll == 2.0_dp)) then
    print *, "Test Passed: sgll and zgll arrays correctly set."
  else
    print *, "Test Failed."
  endif

  ! Clean up
  deallocate(sgll)
  deallocate(zgll)
end program test_data_gllmesh