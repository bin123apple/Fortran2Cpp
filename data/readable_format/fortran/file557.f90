module cdotc_mod
    implicit none
    contains

    complex function cdotc(n, cx, incx, cy, incy)
        complex, intent(in) :: cx(*), cy(*)
        integer, intent(in) :: n, incx, incy
        complex :: ctemp
        integer :: i, ix, iy

        ctemp = (0.0, 0.0)
        if (n <= 0) return
        ix = 1
        iy = 1
        if (incx < 0) ix = (-n + 1) * incx + 1
        if (incy < 0) iy = (-n + 1) * incy + 1

        do i = 1, n
            if (incx == 1 .and. incy == 1) then
                ctemp = ctemp + conjg(cx(i)) * cy(i)
            else
                ctemp = ctemp + conjg(cx(ix)) * cy(iy)
                ix = ix + incx
                iy = iy + incy
            endif
        end do

        cdotc = ctemp
    end function cdotc
end module cdotc_mod

program test_cdotc
    use cdotc_mod
    implicit none
    complex :: result
    complex, allocatable :: cx(:), cy(:)
    integer :: n, incx, incy

    ! Test 1
    n = 2
    incx = 1
    incy = 1
    allocate(cx(n), cy(n))
    cx = [(1.0, 2.0), (3.0, 4.0)]
    cy = [(5.0, 6.0), (7.0, 8.0)]
    result = cdotc(n, cx, incx, cy, incy)
    print *, "Test 1 Result: ", result

    ! Test 2: Test with incx and incy > 1
    n = 2
    incx = 2
    incy = 2
    allocate(cx(2*n), cy(2*n))
    cx = [(1.0, 2.0), (0.0, 0.0), (3.0, 4.0), (0.0, 0.0)]
    cy = [(5.0, 6.0), (0.0, 0.0), (7.0, 8.0), (0.0, 0.0)]
    result = cdotc(n, cx, incx, cy, incy)
    print *, "Test 2 Result: ", result

end program test_cdotc