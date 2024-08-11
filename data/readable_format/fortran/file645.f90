program main
    implicit none
    
    ! Declarations
    integer :: result_sf, result_vf
    
    ! Simulating the different function calls
    call ppm_fmm_traverse_s_sf(result_sf)
    print *, 'ppm_fmm_traverse_s_sf result:', result_sf
    
    call ppm_fmm_traverse_d_sf(result_sf)
    print *, 'ppm_fmm_traverse_d_sf result:', result_sf
    
    call ppm_fmm_traverse_s_vf(result_vf)
    print *, 'ppm_fmm_traverse_s_vf result:', result_vf
    
    call ppm_fmm_traverse_d_vf(result_vf)
    print *, 'ppm_fmm_traverse_d_vf result:', result_vf

end program main

! Function implementations
subroutine ppm_fmm_traverse_s_sf(result)
    integer, intent(out) :: result
    ! Implementation for single precision, scalar field
    result = 1
end subroutine ppm_fmm_traverse_s_sf

subroutine ppm_fmm_traverse_d_sf(result)
    integer, intent(out) :: result
    ! Implementation for double precision, scalar field
    result = 2
end subroutine ppm_fmm_traverse_d_sf

subroutine ppm_fmm_traverse_s_vf(result)
    integer, intent(out) :: result
    ! Implementation for single precision, vector field
    result = 3
end subroutine ppm_fmm_traverse_s_vf

subroutine ppm_fmm_traverse_d_vf(result)
    integer, intent(out) :: result
    ! Implementation for double precision, vector field
    result = 4
end subroutine ppm_fmm_traverse_d_vf