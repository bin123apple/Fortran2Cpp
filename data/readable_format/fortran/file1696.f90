program prgm3
    implicit none
    integer, parameter :: n = 10, k = 3
    integer :: i, j
    integer, dimension(n,n) :: y
    integer :: res1(n), res2(n)
    logical :: arrays_are_different

    do i=1,n
        do j=1,n
            y(i,j) = n*i + j
        end do
    end do
    res2 = y(k,:)

    y(k,4:n) = y(k,3:n-1)
    y(k,3) = 0
    res1 = y(k,:)
    y(k,:) = res2
    y(k,n:4:-1) = y(k,n-1:3:-1)
    y(k,3) = 0
    res2 = y(k,:)

    arrays_are_different = .false.
    do i = 1, n
        if (res1(i) /= res2(i)) then
            arrays_are_different = .true.
            exit
        end if
    end do

    if (arrays_are_different) then
        print *, "Test Failed: Arrays are different."
    else
        print *, "Test Passed: Arrays are identical."
    end if
end program prgm3