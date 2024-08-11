program main
    implicit none
    ! Define global variables here (previously in global_numbers)
    integer, parameter :: Nx = 10
    integer, parameter :: nvars = 5
    ! Define arrays here (previously in arrays)
    real, allocatable :: x(:)
    real, allocatable :: u(:,:)
    real, allocatable :: u_p(:,:)
    real, allocatable :: rhs_u(:,:)
    real, allocatable :: du(:,:)
    real, allocatable :: Mom(:)

    ! Allocate arrays
    call allocate_memory(Nx, nvars, x, u, u_p, rhs_u, du, Mom)

    ! Use the allocated arrays for some operations...

    ! Deallocate to prevent memory leaks
    call deallocate_memory(x, u, u_p, rhs_u, du, Mom)

contains

    subroutine allocate_memory(Nx, nvars, x, u, u_p, rhs_u, du, Mom)
        integer, intent(in) :: Nx, nvars
        real, allocatable, intent(inout) :: x(:), u(:,:), u_p(:,:), rhs_u(:,:), du(:,:), Mom(:)

        allocate(x(0:Nx))
        allocate(u(1:nvars,0:Nx))
        allocate(u_p(1:nvars,0:Nx))
        allocate(rhs_u(1:nvars,0:Nx))
        allocate(du(1:nvars,0:Nx))
        allocate(Mom(0:Nx))
    end subroutine allocate_memory

    subroutine deallocate_memory(x, u, u_p, rhs_u, du, Mom)
        real, allocatable, intent(inout) :: x(:), u(:,:), u_p(:,:), rhs_u(:,:), du(:,:), Mom(:)

        deallocate(x)
        deallocate(u)
        deallocate(u_p)
        deallocate(rhs_u)
        deallocate(du)
        deallocate(Mom)
    end subroutine deallocate_memory

end program main