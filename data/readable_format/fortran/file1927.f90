program test_allocation
    implicit none
    integer, allocatable :: j(:,:)

    ! Check if the 'j' array is allocated (it will not be at this point)
    print *, "Before allocation: ", allocated(j)
    
    ! Allocate the array
    allocate(j(2,2))
    
    ! Check again after allocation
    print *, "After allocation: ", allocated(j)
    
    ! Clean up
    if (allocated(j)) deallocate(j)
end program test_allocation