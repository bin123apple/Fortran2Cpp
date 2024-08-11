! main.f90
module m
    implicit none
    type :: t
        integer, allocatable :: CAF(:)
    end type t
end module m

program test
    use m
    type(t), target :: x, y
    integer, pointer :: ptr(:)
    integer :: errors
    errors = 0

    allocate(x%CAF(1), y%CAF(1))
    ptr => y%CAF
    ptr(1) = 6
    
    ! Check allocations
    if (.not.allocated(x%CAF) .or. .not.allocated(y%CAF)) then
        print *, "Allocation failed"
        errors = errors + 1
    endif

    if (y%CAF(1) /= 6) then
        print *, "Value assignment failed"
        errors = errors + 1
    endif

    x%CAF = y%CAF  ! This makes a copy in Fortran, not sharing
    ptr(1) = 123

    if (y%CAF(1) /= 123) then
        print *, "Value reassignment failed"
        errors = errors + 1
    endif

    if (x%CAF(1) == 123) then  ! This should fail, showing they don't share the same memory
        print *, "Memory sharing failed"
        errors = errors + 1
    endif

    ! Final check on errors
    if (errors == 0) then
        print *, "All tests passed."
    else
        print *, "Tests failed."
    endif

    deallocate(x%CAF, y%CAF)
end program test