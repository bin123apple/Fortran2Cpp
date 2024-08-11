module ppm_module_mesh_alloc
    implicit none
    contains

    subroutine ppm_mesh_alloc_equi()
        ! Example implementation of the procedure
        print *, "Allocating and initializing mesh..."
        ! Here, add the actual mesh allocation and initialization code
    end subroutine ppm_mesh_alloc_equi

end module ppm_module_mesh_alloc

program main
    use ppm_module_mesh_alloc
    implicit none

    ! Call the mesh allocation subroutine
    call ppm_mesh_alloc_equi()

    print *, "Mesh allocation and initialization completed."

end program main