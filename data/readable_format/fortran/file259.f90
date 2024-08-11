program test_socal_model
  implicit none

  ! Define the constants directly in the program
  integer, parameter :: IFLAG_HALFSPACE_MOHO = 1
  integer, parameter :: IFLAG_MOHO_16km = 2
  integer, parameter :: IFLAG_ONE_LAYER_TOPOGRAPHY = 3
  integer, parameter :: IFLAG_BASEMENT_TOPO = 4

  double precision rho, vp, vs

  ! Test case 1: IFLAG_HALFSPACE_MOHO
  call socal_model(IFLAG_HALFSPACE_MOHO, rho, vp, vs)
  print *, "IFLAG_HALFSPACE_MOHO: ", rho, vp, vs

  ! Test case 2: IFLAG_MOHO_16km
  call socal_model(IFLAG_MOHO_16km, rho, vp, vs)
  print *, "IFLAG_MOHO_16km: ", rho, vp, vs

  ! Test case 3: IFLAG_ONE_LAYER_TOPOGRAPHY
  call socal_model(IFLAG_ONE_LAYER_TOPOGRAPHY, rho, vp, vs)
  print *, "IFLAG_ONE_LAYER_TOPOGRAPHY: ", rho, vp, vs

  ! Test case 4: IFLAG_BASEMENT_TOPO
  call socal_model(IFLAG_BASEMENT_TOPO, rho, vp, vs)
  print *, "IFLAG_BASEMENT_TOPO: ", rho, vp, vs

  ! Test case 5: Default case
  call socal_model(-1, rho, vp, vs) ! Assuming -1 is not used by any flags
  print *, "Default case: ", rho, vp, vs

contains

  subroutine socal_model(idoubling, rho, vp, vs)
    implicit none
    integer :: idoubling
    double precision :: rho, vp, vs

    ! Assuming the constants are defined as follows:
    ! integer, parameter :: IFLAG_HALFSPACE_MOHO = 1
    ! integer, parameter :: IFLAG_MOHO_16km = 2
    ! integer, parameter :: IFLAG_ONE_LAYER_TOPOGRAPHY = 3
    ! integer, parameter :: IFLAG_BASEMENT_TOPO = 4

    if (idoubling == IFLAG_HALFSPACE_MOHO) then
          vp=7.8d0
          vs=4.5d0
          rho=3.0d0
    else if (idoubling == IFLAG_MOHO_16km) then
          vp=6.7d0
          vs=3.87d0
          rho=2.8d0
    else if (idoubling == IFLAG_ONE_LAYER_TOPOGRAPHY .or. idoubling == IFLAG_BASEMENT_TOPO) then
          vp=5.5d0
          vs=3.18d0
          rho=2.4d0
    else
          vp=6.3d0
          vs=3.64d0
          rho=2.67d0
    endif

    vp = vp * 1000.d0
    vs = vs * 1000.d0
    rho = rho * 1000.d0

  end subroutine socal_model

end program test_socal_model