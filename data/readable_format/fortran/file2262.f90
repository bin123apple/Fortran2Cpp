! Define precision macros
#define SINGLE_PRECISION 1
#define DOUBLE_PRECISION 2

program main
    implicit none
    ! Your main program code goes here
    ! For example, to test the procedures:
    call ppm_topo_get()
    call ppm_topo_get_decomp_s()
    call ppm_topo_get_decomp_d()
    call ppm_topo_get_meshinfo()
end program main

! Define all your procedures below

subroutine ppm_topo_get()
    ! Implementation of ppm_topo_get
    print *, "ppm_topo_get called"
end subroutine ppm_topo_get

subroutine ppm_topo_get_decomp_s()
    ! Implementation of ppm_topo_get_decomp_s (single precision)
    print *, "ppm_topo_get_decomp_s (single precision) called"
end subroutine ppm_topo_get_decomp_s

subroutine ppm_topo_get_decomp_d()
    ! Implementation of ppm_topo_get_decomp_d (double precision)
    print *, "ppm_topo_get_decomp_d (double precision) called"
end subroutine ppm_topo_get_decomp_d

subroutine ppm_topo_get_meshinfo()
    ! Implementation of ppm_topo_get_meshinfo
    print *, "ppm_topo_get_meshinfo called"
end subroutine ppm_topo_get_meshinfo