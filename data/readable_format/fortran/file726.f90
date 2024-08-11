subroutine izero(ia, nn)
    implicit none
    integer, intent(inout) :: ia(*)
    integer, intent(in) :: nn
    integer :: n
    do n = 1, nn
        ia(n) = 0
    end do
end subroutine izero

program test_izero
    implicit none
    integer, allocatable :: test_array(:)
    integer :: i, n
    logical :: test_passed

    n = 5
    allocate(test_array(n))

    ! Initialize the array with non-zero values
    test_array = (/1, 2, 3, 4, 5/)

    call izero(test_array, n)

    test_passed = .true.
    do i = 1, n
        if (test_array(i) /= 0) then
            test_passed = .false.
            exit
        endif
    end do

    if (test_passed) then
        print *, "Test Passed."
    else
        print *, "Test Failed."
    endif

    deallocate(test_array)
end program test_izero