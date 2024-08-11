program work_type_demo
    implicit none

    ! Type definition
    type work_type
        integer :: ntotal_kernel
        integer :: ndimensions
        integer :: nvertices
        real, allocatable :: vertices(:,:)
        real, allocatable :: kernel_values(:,:)
    end type work_type

    ! Declare an instance of work_type
    type(work_type) :: wt

    ! Main program
    call init_work_type(wt, 10, 2, 5)
    print *, "ntotal_kernel: ", wt%ntotal_kernel
    print *, "ndimensions: ", wt%ndimensions
    print *, "nvertices: ", wt%nvertices
    ! Add more prints or checks here as needed to verify correct initialization

contains

    subroutine init_work_type(wt, nkern, ndim, nverts)
        type(work_type), intent(out) :: wt
        integer, intent(in) :: nkern, ndim, nverts

        wt%ntotal_kernel = nkern
        wt%nvertices = nverts
        wt%ndimensions = ndim

        allocate(wt%vertices(1:wt%ndimensions, 1:wt%nvertices))
        allocate(wt%kernel_values(wt%ntotal_kernel, 1:wt%nvertices))
        wt%vertices = 0
        wt%kernel_values = 0
    end subroutine init_work_type

end program work_type_demo