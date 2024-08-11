program bug_test
    implicit none
    integer :: i
    real, dimension(2) :: a, b
    real :: x

    ! Test values
    a(1) = -5.0
    a(2) = 3.0

    do i = 1, 2
        x = abs(a(i))
        b(i) = x
    end do

    ! Printing results for manual verification
    print *, "Expected: 5.0, 3.0"
    print *, "Got: ", b(1), b(2)
end program bug_test