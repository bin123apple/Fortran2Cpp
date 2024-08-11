program where_16
    implicit none
    integer :: a(9) = (/0, 0, 0, 1, 1, 1, 2, 2, 2/)
    integer :: b(9) = (/0, 1, 2, 0, 1, 2, 0, 1, 2/)
    integer :: c(9) = (/0, 0, 0, 0, 0, 0, 0, 0, 0/)
    integer :: expected_c(9) = (/1, 2, 3, 4, 5, 6, 7, 8, 9/)
    integer :: i
    logical :: test_passed = .true.

    do i = 1, 9
        if (a(i) == 0) then
            if (b(i) == 0) then
                c(i) = 1
            else if (b(i) == 1) then
                c(i) = 2
            else
                c(i) = 3
            end if
        else if (a(i) == 1) then
            if (b(i) == 0) then
                c(i) = 4
            else if (b(i) == 1) then
                c(i) = 5
            else
                c(i) = 6
            end if
        else
            if (b(i) == 0) then
                c(i) = 7
            else if (b(i) == 1) then
                c(i) = 8
            else
                c(i) = 9
            end if
        end if
    end do

    ! Unit test
    do i = 1, 9
        if (c(i) /= expected_c(i)) then
            test_passed = .false.
            exit
        end if
    end do

    if (test_passed) then
        print *, "Test passed."
    else
        print *, "Test failed."
    end if
end program where_16