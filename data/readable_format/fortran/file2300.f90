program test_where_15
    implicit none
    integer :: a(5)
    integer :: b(5)
    integer :: expected_b(5)
    integer :: i

    a = (/1, 2, 3, 4, 5/)
    b = (/0, 0, 0, 0, 0/)
    expected_b = (/0, 2, 2, 2, 2/)

    where (a /= 1)
        b = 2
    end where

    do i = 1, size(b)
        if (b(i) /= expected_b(i)) then
            print *, "Test failed: b(", i, ") = ", b(i)
            call abort
        end if
    end do

    print *, "Test passed: b = ", b

end program test_where_15