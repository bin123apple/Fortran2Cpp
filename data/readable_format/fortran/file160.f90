module mod_alloc
    implicit none
    private
    public :: alloc
    public :: dealloc

contains

    subroutine alloc(x, n)
        real, allocatable, intent(in out) :: x(:)
        integer, intent(in) :: n
        integer :: stat
        character(len=100) :: errmsg

        if (allocated(x)) call dealloc(x)

        allocate(x(n), stat=stat, errmsg=errmsg)
        if (stat > 0) error stop errmsg

    end subroutine alloc

    subroutine dealloc(x)
        real, allocatable, intent(in out) :: x(:)
        integer :: stat
        character(len=100) :: errmsg

        if (allocated(x)) then
            deallocate(x, stat=stat, errmsg=errmsg)
            if (stat > 0) error stop errmsg
        end if
    end subroutine dealloc

end module mod_alloc

program test_mod_alloc
    use mod_alloc
    implicit none
    real, allocatable :: test_array(:)
    integer :: n

    ! Test normal allocation and deallocation
    n = 5
    call alloc(test_array, n)
    if (.not. allocated(test_array)) then
        print *, "Test failed: Array not allocated."
    else
        print *, "Test passed: Array successfully allocated."
    end if
    call dealloc(test_array)
    if (allocated(test_array)) then
        print *, "Test failed: Array not deallocated."
    else
        print *, "Test passed: Array successfully deallocated."
    end if

    ! Test deallocating already deallocated memory (should handle gracefully)
    call dealloc(test_array)  ! Nothing should happen, no errors
    print *, "Test passed: Gracefully handled deallocation of already deallocated memory."

    ! Note: It's difficult to simulate an allocation failure for testing without specific system conditions.
end program test_mod_alloc