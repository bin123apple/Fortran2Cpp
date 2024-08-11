program test_ranstd
    implicit none
    real, allocatable :: arr(:)
    integer :: n, i

    ! Test case 1
    n = 5
    allocate(arr(n))
    arr = [2.0, 4.0, 4.0, 4.0, 5.0]
    call ranstd(arr, n)
    print *, 'Test Case 1 Results:'
    do i = 1, n
        print *, arr(i)
    end do

    ! Test case 2
    n = 3
    allocate(arr(n))
    arr = [1.0, 2.0, 3.0]
    call ranstd(arr, n)
    print *, 'Test Case 2 Results:'
    do i = 1, n
        print *, arr(i)
    end do

    deallocate(arr)
end program test_ranstd

subroutine ranstd( x, n )
    real, dimension(n) :: x
    real :: sum1, sum2
    integer :: i

    if( n .le. 1 ) return
    sum1 = 0.
    sum2 = 0.
    do i = 1, n
        sum1 = sum1 + x(i)
        sum2 = sum2 + x(i)**2
    end do
    sum1 = sum1 / n
    sum2 = sum2 / n
    if( sum2 .gt. 0. ) then
       sum2 = 1. / sqrt( sum2 - sum1**2 )
    else
       write(6,*)' ranstd: n,sum2=',n,sum2, &
            ' cannot standardize variance'
       sum2 = 1.
    endif
    sum1 = -sum1*sum2
    do i = 1, n
        x(i) = sum1 + sum2 * x(i)
    end do
end subroutine ranstd