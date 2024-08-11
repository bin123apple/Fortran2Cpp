program testMedian
    implicit none
    double precision, dimension(5) :: oddArray = [3.0, 1.0, 2.0, 5.0, 4.0]
    double precision, dimension(6) :: evenArray = [6.0, 1.0, 5.0, 2.0, 4.0, 3.0]
    double precision :: median

    call per_getmed(oddArray, 5)
    median = oddArray((5+1)/2)
    print *, "Median of oddArray: ", median

    call per_getmed(evenArray, 6)
    median = (evenArray(6/2) + evenArray(6/2 + 1)) / 2.0
    print *, "Median of evenArray: ", median
end program testMedian

subroutine per_getmed(in,n)
    integer :: n, i, j
    double precision, dimension(n) :: in
    double precision :: temp

    do i=1,n
        do j=i+1,n
            if (in(j) > in(i)) then
                temp = in(i)
                in(i) = in(j)
                in(j) = temp
            end if
        end do
    end do
end subroutine per_getmed