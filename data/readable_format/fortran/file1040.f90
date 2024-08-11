! p.f90
program p
    implicit none
    type t
        integer :: dummy
    end type t
    class(t), allocatable :: x

    allocate(x)
    if (allocated(x)) then
        print *, "Allocation successful."
    else
        print *, "Allocation failed."
    end if

    deallocate(x)
    if (.not. allocated(x)) then
        print *, "Deallocation successful."
    else
        print *, "Deallocation failed."
    end if
end program p