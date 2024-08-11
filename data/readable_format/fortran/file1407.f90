program test_loops
    implicit none
    integer :: i
    real :: r

    do i = 1, 0
    end do
    print *, "Loop with integer counter from 1 to 0 did not run."

    do i = 1, -1, 1
    end do
    print *, "Loop with integer counter from 1 to -1 with step 1 did not run."

    do i = 1, 2, -1
    end do
    print *, "Loop with integer counter from 1 to 2 with step -1 did not run."

    ! Step of 0 is undefined; no test provided.

    do r = 1, 0
    end do
    print *, "Loop with real counter from 1 to 0 did not run."

    do r = 1, -1, 1
    end do
    print *, "Loop with real counter from 1 to -1 with step 1 did not run."

    do r = 1, 2, -1
    end do
    print *, "Loop with real counter from 1 to 2 with step -1 did not run."

    ! Step of 0 is undefined; no test provided.

end program test_loops