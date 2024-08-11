subroutine dswap(n, dx, incx, dy, incy)
    implicit none
    double precision, dimension(*) :: dx, dy
    double precision :: dtemp
    integer :: i, incx, incy, ix, iy, n

    if (n <= 0) return
    ix = 1
    iy = 1
    if (incx < 0) ix = (-n+1) * incx + 1
    if (incy < 0) iy = (-n+1) * incy + 1
    do i = 1, n
        dtemp = dx(ix)
        dx(ix) = dy(iy)
        dy(iy) = dtemp
        ix = ix + incx
        iy = iy + incy
    end do
end subroutine dswap

program test_dswap
    implicit none
    double precision, allocatable :: dx(:), dy(:)
    integer :: n, incx, incy

    ! Test 1: Simple swap
    n = 5
    allocate(dx(n), dy(n))
    dx = (/1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0/)
    dy = (/5.0d0, 4.0d0, 3.0d0, 2.0d0, 1.0d0/)
    incx = 1
    incy = 1
    call dswap(n, dx, incx, dy, incy)
    print '("Test 1: dx:", *(F6.2))', dx
    print '("Test 1: dy:", *(F6.2))', dy

    ! Test 2: Strided swap
    dx = (/1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0/)
    dy = (/5.0d0, 4.0d0, 3.0d0, 2.0d0, 1.0d0/)
    incx = 2
    incy = 2
    call dswap(3, dx, incx, dy, incy)  ! Adjusted to affect only 3 elements due to stride
    print '("Test 2: dx:", *(F6.2))', dx
    print '("Test 2: dy:", *(F6.2))', dy

    deallocate(dx, dy)
end program test_dswap