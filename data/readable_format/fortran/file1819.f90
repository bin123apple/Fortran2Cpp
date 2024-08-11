program test_program
    implicit none

    ! Type definition
    type :: t
    end type t

    ! Variable declarations
    type(t), allocatable :: xx(:)
    integer :: stat
    character(len=200) :: errmsg

    ! Allocate xx with a specified size for demonstration
    allocate(xx(10), stat=stat, errmsg=errmsg)
    if (stat /= 0) then
        print *, "Allocation of xx failed:", trim(errmsg)
        stop
    end if

    ! Perform operations or manipulations with xx as needed
    ! For demonstration, we simply proceed to deallocation

    ! Deallocate xx
    deallocate(xx, stat=stat, errmsg=errmsg)
    if (stat /= 0) then
        print *, "Deallocation of xx failed:", trim(errmsg)
        stop
    end if

    ! Print a success message to indicate completion without errors
    print *, "Program completed successfully."

end program test_program