program test_zdotcsub
  implicit none
  double complex :: zdotcr
  double complex, dimension(3) :: x, y
  integer :: n, incx, incy

  ! Initialize test data
  n = 3
  incx = 1
  incy = 1
  x = [(1.0d0, 2.0d0), (3.0d0, 4.0d0), (5.0d0, -6.0d0)]
  y = [(2.0d0, -1.0d0), (-4.0d0, 3.0d0), (7.0d0, 8.0d0)]

  ! Call the subroutine
  call zdotcsub(zdotcr, n, x, incx, y, incy)

  ! Print the result
  print *, 'zdotcr = ', zdotcr

contains

  subroutine zdotcsub(zdotcr, n, x, incx, y, incy)
    double complex zdotcr, x(*), y(*)
    integer n, incx, incy
    double complex :: sum
    integer :: i

    sum = (0.0d0, 0.0d0)
    do i = 1, n
      sum = sum + conjg(x(i)) * y(i)
    end do
    zdotcr = sum
  end subroutine zdotcsub

end program test_zdotcsub