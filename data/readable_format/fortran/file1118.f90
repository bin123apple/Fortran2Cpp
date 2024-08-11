program test_sswap
  implicit none
  real :: sx(5) = [1.0, 2.0, 3.0, 4.0, 5.0]
  real :: sy(5) = [5.0, 4.0, 3.0, 2.0, 1.0]
  integer :: i

  call sswap(5, sx, 1, sy, 1)
  
  print *, 'sx after swap: '
  do i=1,5
     print *, sx(i)
  end do
  
  print *, 'sy after swap: '
  do i=1,5
     print *, sy(i)
  end do

contains

  subroutine sswap(n, sx, incx, sy, incy)
    real, dimension(*) :: sx, sy
    real :: stemp
    integer :: i, incx, incy, ix, iy, m, mp1, n

    if (n <= 0) return
    if (incx == 1 .and. incy == 1) then
      m = mod(n, 3)
      if (m /= 0) then
        do i = 1, m
          stemp = sx(i)
          sx(i) = sy(i)
          sy(i) = stemp
        end do
      end if
      if (n < 3) return
      mp1 = m + 1
      do i = mp1, n, 3
        stemp = sx(i)
        sx(i) = sy(i)
        sy(i) = stemp
        stemp = sx(i + 1)
        sx(i + 1) = sy(i + 1)
        sy(i + 1) = stemp
        stemp = sx(i + 2)
        sx(i + 2) = sy(i + 2)
        sy(i + 2) = stemp
      end do
    else
      ix = 1
      iy = 1
      if (incx < 0) ix = (-n + 1) * incx + 1
      if (incy < 0) iy = (-n + 1) * incy + 1
      do i = 1, n
        stemp = sx(ix)
        sx(ix) = sy(iy)
        sy(iy) = stemp
        ix = ix + incx
        iy = iy + incy
      end do
    end if
  end subroutine sswap

end program test_sswap