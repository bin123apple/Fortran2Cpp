program test_m_boundary_params_sph_MHD
  implicit none

  ! Type definitions
  type sph_boundary_type
    ! Assuming the structure of sph_boundary_type. Adjust according to actual definition.
    integer :: dummy
  end type sph_boundary_type

  ! Declarations similar to those in the module m_boundary_params_sph_MHD
  type(sph_boundary_type) :: sph_bc_U
  type(sph_boundary_type) :: sph_bc_B
  type(sph_boundary_type) :: sph_bc_T
  type(sph_boundary_type) :: sph_bc_C

  real, allocatable :: vp_ICB_bc(:)
  real, allocatable :: vt_ICB_bc(:)
  real, allocatable :: vp_CMB_bc(:)
  real, allocatable :: vt_CMB_bc(:)

  integer, parameter :: jmax = 5
  integer :: i

  ! Allocate the arrays
  call allocate_vsp_bc_array(jmax)

  ! Check initialization
  do i = 1, jmax
    if (vp_ICB_bc(i) /= 0.0 .or. vt_ICB_bc(i) /= 0.0 .or. &
        vp_CMB_bc(i) /= 0.0 .or. vt_CMB_bc(i) /= 0.0) then
      print *, "Error: Arrays not properly initialized."
      stop
    endif
  end do
  print *, "Allocation and initialization test passed."

  ! Deallocate the arrays
  call deallocate_vsp_bc_array
  print *, "Deallocation test passed."

contains

  subroutine allocate_vsp_bc_array(jmax)
    integer, intent(in) :: jmax

    allocate(vp_ICB_bc(jmax))
    allocate(vt_ICB_bc(jmax))
    allocate(vp_CMB_bc(jmax))
    allocate(vt_CMB_bc(jmax))
    vp_ICB_bc = 0.0
    vt_ICB_bc = 0.0
    vp_CMB_bc = 0.0
    vt_CMB_bc = 0.0
  end subroutine allocate_vsp_bc_array

  subroutine deallocate_vsp_bc_array
    deallocate(vp_ICB_bc, vt_ICB_bc)
    deallocate(vp_CMB_bc, vt_CMB_bc)
  end subroutine deallocate_vsp_bc_array

end program test_m_boundary_params_sph_MHD