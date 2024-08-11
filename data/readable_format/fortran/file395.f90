! saxpy.f90
subroutine saxpy(n,sa,sx,incx,sy,incy)
    real sx(1),sy(1),sa
    integer i,incx,incy,ix,iy,m,mp1,n

    if(n.le.0)return
    if (sa .eq. 0.0) return
    if(incx.eq.1.and.incy.eq.1)go to 20

    ix = 1
    iy = 1
    if(incx.lt.0)ix = (-n+1)*incx + 1
    if(incy.lt.0)iy = (-n+1)*incy + 1
    do 10 i = 1,n
        sy(iy) = sy(iy) + sa*sx(ix)
        ix = ix + incx
        iy = iy + incy
10  continue
    return

20  m = mod(n,4)
    if( m .eq. 0 ) go to 40
    do 30 i = 1,m
        sy(i) = sy(i) + sa*sx(i)
30  continue
    if( n .lt. 4 ) return
40  mp1 = m + 1
    do 50 i = mp1,n,4
        sy(i) = sy(i) + sa*sx(i)
        sy(i + 1) = sy(i + 1) + sa*sx(i + 1)
        sy(i + 2) = sy(i + 2) + sa*sx(i + 2)
        sy(i + 3) = sy(i + 3) + sa*sx(i + 3)
50  continue
    return
end subroutine saxpy

! Test Program
program test_saxpy
    external saxpy
    integer :: n, incx, incy
    real :: sa
    real, allocatable :: sx(:), sy(:)

    ! Test parameters
    n = 5
    sa = 2.0
    incx = 1
    incy = 1
    allocate(sx(n), sy(n))

    ! Initialize arrays
    sx = (/1.0, 2.0, 3.0, 4.0, 5.0/)
    sy = (/5.0, 4.0, 3.0, 2.0, 1.0/)

    ! Call SAXPY subroutine
    call saxpy(n, sa, sx, incx, sy, incy)

    ! Output the results
    print *, "SY after SAXPY:"
    print *, sy

    deallocate(sx, sy)
end program test_saxpy