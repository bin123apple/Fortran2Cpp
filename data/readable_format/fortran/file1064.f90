program main
    implicit none
    integer, allocatable :: array(:)
    integer :: i, n

    ! Set array size
    n = 10

    ! Allocate and initialize array
    allocate(array(n))
    do i = 1, n
        array(i) = i
    end do

    ! Tests
    if (size(array) .eq. n) then
        print *, "Test 1 Passed: Array size is correct."
    else
        print *, "Test 1 Failed: Array size is incorrect."
    end if

    if (array(1) .eq. 1) then
        print *, "Test 2 Passed: First element is 1."
    else
        print *, "Test 2 Failed: First element is not 1."
    end if

    ! Clean up
    deallocate(array)
end program