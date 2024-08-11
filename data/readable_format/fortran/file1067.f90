program test_integration
    implicit none

    ! Declarations equivalent to those in the module gsbpmod
    integer :: nclx1, ncly1
    integer, allocatable :: lstpl(:), lstpm(:)
    ! Additional variables for demonstration
    integer :: i

    ! Initialize variables
    nclx1 = 10
    ncly1 = 20

    ! Allocation
    allocate(lstpl(nclx1))
    allocate(lstpm(ncly1))

    ! Initialization
    lstpl = 1
    lstpm = 2

    ! Example operation: Increment each element by 1
    do i = 1, nclx1
        lstpl(i) = lstpl(i) + 1
    end do
    do i = 1, ncly1
        lstpm(i) = lstpm(i) + 1
    end do

    ! Example assertion/check
    if (all(lstpl == 2) .and. all(lstpm == 3)) then
        print *, "Test Passed: Arrays correctly manipulated."
    else
        print *, "Test Failed."
    endif

    ! Clean-up
    deallocate(lstpl, lstpm)

end program test_integration