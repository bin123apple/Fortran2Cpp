program test_nidentll
    implicit none
    integer, parameter :: n = 5
    integer(kind=8) :: x(n) = [1, 3, 5, 7, 9]
    integer(kind=8) :: px
    integer :: id, i
    integer(kind=8), dimension(4) :: test_values = [1, 5, 9, 11]
    integer, dimension(4) :: expected_ids = [1, 3, 5, 0]

    do i = 1, size(test_values)
        px = test_values(i)
        call nidentll(x, px, n, id)
        print *, "Test ", i, ": px=", px, " Expected ID=", expected_ids(i), " Got ID=", id
        if (id .eq. expected_ids(i)) then
            print *, "Test Passed"
        else
            print *, "Test Failed"
        endif
    end do
end program test_nidentll

subroutine nidentll(x, px, n, id)
    implicit none
    integer n, id, n2, m
    integer(kind=8) :: x(*)
    integer(kind=8) :: px
    id = 0
    if (n == 0) return
    n2 = n + 1
    do
        m = (n2 + id) / 2
        if (px >= x(m)) then
            id = m
        else
            n2 = m
        endif
        if ((n2 - id) == 1) exit
    end do
end subroutine nidentll