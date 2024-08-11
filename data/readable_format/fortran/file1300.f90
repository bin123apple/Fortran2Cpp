program test_zdotuf
  implicit none
  double complex, allocatable :: zx(:), zy(:)
  double complex :: result
  integer :: n

  ! Example usage
  n = 2
  allocate(zx(n))
  allocate(zy(n))
  zx = [(1.0d0, 2.0d0), (3.0d0, 4.0d0)]
  zy = [(5.0d0, 6.0d0), (7.0d0, 8.0d0)]
  
  result = zdotuf(n, zx, 1, zy, 1)
  print *, "Test Result: ", result
  ! Expected: (-18.0, 44.0)

  deallocate(zx)
  deallocate(zy)

contains
  double complex function zdotuf(n,zx,incx,zy,incy)
    double complex zx(*),zy(*),ztemp
    integer i,incx,incy,ix,iy,n
    ztemp = (0.0d0,0.0d0)
    if(n.le.0)return
    ix = 1
    iy = 1
    if(incx.lt.0)ix = (-n+1)*incx + 1
    if(incy.lt.0)iy = (-n+1)*incy + 1
    do i = 1,n
      ztemp = ztemp + zx(ix)*zy(iy)
      ix = ix + incx
      iy = iy + incy
    end do
    zdotuf = ztemp
  end function zdotuf
end program test_zdotuf