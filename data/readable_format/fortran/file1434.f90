module scalar_pool_mod
    implicit none
    private
    public :: scalar_pool

    type, public :: scalar_pool
        real, allocatable :: pool(:)
        integer :: size
    contains
        procedure :: init => init_pool
        procedure :: acquire => acquire_resource
        procedure :: release => release_resource
        procedure :: destroy => destroy_pool
    end type scalar_pool

contains
    subroutine init_pool(this, size)
        class(scalar_pool), intent(inout) :: this
        integer, intent(in) :: size
        
        this%size = size
        allocate(this%pool(size))
        this%pool = 0.0  ! Initialize pool values to 0.0
    end subroutine init_pool

    subroutine acquire_resource(this, id, resource)
        class(scalar_pool), intent(inout) :: this
        integer, intent(in) :: id
        real, intent(out) :: resource
        
        if (id > 0 .and. id <= this%size) then
            resource = this%pool(id)
        else
            resource = -1.0  ! Indicate an error
        endif
    end subroutine acquire_resource

    subroutine release_resource(this, id, resource)
        class(scalar_pool), intent(inout) :: this
        integer, intent(in) :: id
        real, intent(in) :: resource
        
        if (id > 0 .and. id <= this%size) then
            this%pool(id) = resource
        endif
    end subroutine release_resource

    subroutine destroy_pool(this)
        class(scalar_pool), intent(inout) :: this
        
        if (allocated(this%pool)) then
            deallocate(this%pool)
        endif
    end subroutine destroy_pool

end module scalar_pool_mod

program test_scalar_pool
    use scalar_pool_mod
    implicit none

    type(scalar_pool) :: pool
    real :: resource
    integer :: id

    ! Initialize pool with a size of 10
    call pool%init(10)

    ! Test successful resource acquisition
    id = 1
    call pool%acquire(id, resource)
    print *, 'Acquired resource from id', id, ':', resource

    ! Test acquiring more resources than available
    id = 11
    call pool%acquire(id, resource)
    print *, 'Attempted to acquire resource from id', id, ', successful:', resource < 0.0

    ! Test proper resource release
    id = 1
    resource = 5.0
    call pool%release(id, resource)
    call pool%acquire(id, resource)
    print *, 'Resource value at id', id, 'after release and re-acquire:', resource

    ! Clean up
    call pool%destroy()

end program test_scalar_pool