program decl
    implicit none
    real, allocatable :: s(:)
    integer :: i

    ! Allocate the array with 5 elements
    allocate(s(5))

    ! Assign values to the array
    do i = 1, 5
        s(i) = real(i)
    end do

    ! Print the values to verify correctness
    print *, 'Array values:'
    do i = 1, 5
        print *, s(i)
    end do

    ! Deallocate the array
    deallocate(s)
end program decl