module ddot_module
  implicit none
contains
  double precision function ddot(n, dx, incx, dy, incy)
    integer, intent(in) :: n, incx, incy
    double precision, intent(in) :: dx(*), dy(*)
    integer :: i, ix, iy
    ddot = 0.0d0
    ix = 1
    iy = 1
    if (incx < 0) ix = (-n + 1) * incx + 1
    if (incy < 0) iy = (-n + 1) * incy + 1
    do i = 1, n
      ddot = ddot + dx(ix) * dy(iy)
      ix = ix + incx
      iy = iy + incy
    end do
  end function ddot
end module ddot_module

program test_ddot
  use ddot_module
  implicit none
  double precision :: result
  double precision, allocatable :: dx(:), dy(:)
  integer :: n, incx, incy

  ! Test 1
  n = 5
  incx = 1
  incy = 1
  allocate(dx(n), dy(n))
  dx = (/1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0/)
  dy = (/1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0/)
  result = ddot(n, dx, incx, dy, incy)
  print *, "Test 1: ", result  ! Expected: 55.0

  ! Free allocated memory
  deallocate(dx, dy)
end program test_ddot