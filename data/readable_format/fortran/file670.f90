program test_matrices
    implicit none
    real, dimension(3,3) :: a
    real, dimension(2,3) :: b, c
    integer :: i, j

    ! Initialize matrix a
    do i = 1, 3
        do j = 1, 3
            a(i,j) = real((i-1)*3 + j)
        end do
    end do

    ! Initialize matrices b and c by slicing and reversing parts of a
    b = a(2:1:-1, :)
    c = a(3:2:-1, :)

    ! Print matrices for visual inspection (optional)
    print *, "Matrix a:"
    do i = 1, 3
        print '(*(F4.1))', a(i,:)
    end do

    print *, "Matrix b:"
    do i = 1, 2
        print '(*(F4.1))', b(i,:)
    end do

    print *, "Matrix c:"
    do i = 1, 2
        print '(*(F4.1))', c(i,:)
    end do

    ! Perform unit tests
    ! Expected values are hardcoded for simplicity
    do i = 1, 2
        do j = 1, 3
            if (i == 1) then
                if (b(i,j) /= 4+j-1 .or. c(i,j) /= 7+j-1) then
                    print *, "Test failed for matrices at position", i, j
                    stop
                end if
            else if (i == 2) then
                if (b(i,j) /= 1+j-1 .or. c(i,j) /= 4+j-1) then
                    print *, "Test failed for matrices at position", i, j
                    stop
                end if
            end if
        end do
    end do

    print *, "All tests passed."
end program test_matrices