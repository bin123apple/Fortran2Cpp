program test_fortran_code
    implicit none
    integer :: status
    character(len=5) :: x
    integer :: i

    ! Test case 1: substring not found (expected behavior, no abort)
    x = '12345'
    i = index(x, 'blablabl')
    if (i .ne. 0) then
        call abort
    end if

    ! If we reach this point, the test passed
    print *, 'Test case 1 passed'

    ! Test case 2: substring found (should call abort, but we comment out to test other scenario)
    ! Uncomment the following lines to test the abort behavior
    ! x = '12345blablabl'
    ! i = index(x, 'blablabl')
    ! if (i .ne. 0) then
    !     call abort
    ! end if

    ! If we reach this point, the test passed unexpectedly
    ! print *, 'Test case 2 passed (unexpectedly)'

    ! End the program normally
    stop

end program test_fortran_code