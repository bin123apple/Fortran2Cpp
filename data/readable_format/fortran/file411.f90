program test_openacc
    use openacc
    implicit none
    integer, parameter :: N = 10000
    integer :: i
    integer, dimension(N) :: a, results

    ! Initialize the array 'a'
    a = 1

    ! Perform the computation in parallel
    !$acc parallel loop copyin(a) copyout(results)
    do i=1, N
        results(i) = a(i) * 2
    end do
    !$acc end parallel loop

    ! Verify the results
    do i=1, N
        if (results(i) /= 2) then
            print *, "Test failed at index: ", i
            stop
        endif
    end do

    print *, "All tests passed."

end program test_openacc