program test_arrays
    implicit none
    integer, allocatable :: non_empty(:,:)

    ! Create a 2x2 array filled with 1s to mimic the PAD operation
    allocate(non_empty(2,2))
    non_empty = 1
    non_empty(1, 2) = 2
    non_empty(2, 1) = 2
    non_empty(2, 2) = 2

    ! Print the array for visual inspection
    print *, "Non-empty array:"
    call print_array(non_empty)

contains
    subroutine print_array(arr)
        integer, intent(in) :: arr(:,:)
        integer :: i, j
        do i = 1, size(arr, 1)
            do j = 1, size(arr, 2)
                print *, arr(i, j)
            end do
            print *, " "
        end do
    end subroutine print_array
end program test_arrays