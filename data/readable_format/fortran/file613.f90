module m
    implicit none
    type t
        real, pointer, dimension(:,:) :: a
    end type t
    real, pointer, dimension(:,:) :: a

contains
    subroutine f(pp)
        type(t), target :: pp
        type(t), pointer :: p
        p => pp
        a => p%a
    end subroutine f
end module m

program test
    use m
    implicit none

    type(t) :: pp
    integer, parameter :: numRows = 2, numCols = 3
    real, allocatable, target :: testArray(:,:) ! Mark as target
    integer :: i, j

    ! Allocate and initialize the array
    allocate(testArray(numRows, numCols))
    do i = 1, numRows
        do j = 1, numCols
            testArray(i, j) = real(i * j) ! Example initialization
        end do
    end do

    ! Associate the pointer in pp with testArray
    pp%a => testArray

    ! Call subroutine f
    call f(pp)

    ! Check if the global pointer a points to the same content as pp%a
    if (all(a == pp%a)) then
        print *, "Test passed."
    else
        print *, "Test failed."
    end if

    ! Clean up by deallocating and disassociating pointers
    if (associated(pp%a)) then
        nullify(pp%a)
    end if
    if (allocated(testArray)) then
        deallocate(testArray)
    end if
    if (associated(a)) then
        nullify(a)
    end if
end program test