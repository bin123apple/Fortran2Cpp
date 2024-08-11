program main
    implicit none
    ! Define precision
    integer, parameter :: p = kind(1.0d0)
    
    ! Type definitions
    type alloc_int1d
        integer, allocatable :: v(:)
    end type alloc_int1d

    type alloc_rp1d
        real(p), allocatable :: v(:)
    end type alloc_rp1d

    type alloc_int2d
        integer, allocatable :: v(:,:)
    end type alloc_int2d

    type alloc_rp2d
        real(p), allocatable :: v(:,:)
    end type alloc_rp2d

    ! Example usage
    type(alloc_int1d) :: example_int1d
    type(alloc_rp1d) :: example_rp1d
    type(alloc_int2d) :: example_int2d
    type(alloc_rp2d) :: example_rp2d

    ! Allocate and use the types
    allocate(example_int1d%v(5))
    example_int1d%v = [1,2,3,4,5]
    print *, example_int1d%v

    allocate(example_rp1d%v(5))
    example_rp1d%v = [1.0_p,2.0_p,3.0_p,4.0_p,5.0_p]
    print *, example_rp1d%v

    allocate(example_int2d%v(2,2))
    example_int2d%v = reshape([1,2,3,4], [2,2])
    print *, example_int2d%v

    allocate(example_rp2d%v(2,2))
    example_rp2d%v = reshape([1.0_p,2.0_p,3.0_p,4.0_p], [2,2])
    print *, example_rp2d%v

    ! Clean up
    deallocate(example_int1d%v)
    deallocate(example_rp1d%v)
    deallocate(example_int2d%v)
    deallocate(example_rp2d%v)
    
end program main