program test_array
    implicit none
    integer, parameter :: nmax=165000
    double precision :: x(nmax)
    integer :: i
    logical :: test_passed

    ! Initialize array
    do i = 1, nmax
        x(i) = i
    end do

    ! Check the array size and content
    test_passed = .true.
    do i = 1, nmax
        if (x(i) /= i) then
            test_passed = .false.
            exit
        end if
    end do

    if (test_passed) then
        print *, "Test passed: Array size and initialization are correct."
    else
        print *, "Test failed: Array size or initialization is incorrect."
    end if
end program test_array