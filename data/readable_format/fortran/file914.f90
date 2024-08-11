subroutine sedivm(n, dx, incx, dy, incy)
  implicit none
  integer, intent(in) :: n, incx, incy
  real, intent(in) :: dx(*)
  real, intent(inout) :: dy(*)
  integer :: i, ix, iy

  if (n.le.0) return
  ix = 1
  iy = 1
  if (incx < 0) ix = (-n + 1) * incx + 1
  if (incy < 0) iy = (-n + 1) * incy + 1

  do i = 1, n
     dy(iy) = dy(iy) / dx(ix)
     ix = ix + incx
     iy = iy + incy
  end do
end subroutine sedivm

program test
  implicit none
  real, allocatable :: dx(:), dy(:)
  integer :: n, incx, incy

  ! Test 1
  n = 5
  allocate(dx(n), dy(n))
  dx = (/1, 2, 3, 4, 5/)
  dy = (/10, 20, 30, 40, 50/)
  incx = 1
  incy = 1
  call sedivm(n, dx, incx, dy, incy)
  print *, 'Test 1:', dy

  ! Test 2
  dx = (/1, 2, 3, 4, 5/)
  dy = (/5, 10, 15, 20, 25/)
  incx = 2
  incy = 2
  call sedivm(3, dx, incx, dy, incy)
  print *, 'Test 2:', dy

  ! Test 3
  dx = (/5, 4, 3, 2, 1/)
  dy = (/50, 40, 30, 20, 10/)
  incx = -1
  incy = -1
  call sedivm(5, dx, incx, dy, incy)
  print *, 'Test 3:', dy

  deallocate(dx, dy)
end program test