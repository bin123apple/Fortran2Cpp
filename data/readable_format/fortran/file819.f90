program test_csrot
  implicit none
  complex, allocatable :: cx(:), cy(:)
  complex :: ctemp
  real :: c, s
  integer :: n, incx, incy, i
  
  ! Test 1: Basic functionality
  n = 4
  incx = 1
  incy = 1
  c = 0.5
  s = 0.86602540378 ! sin(60 degrees)
  allocate(cx(n), cy(n))
  
  ! Populate cx and cy
  do i = 1, n
     cx(i) = complex(i, i)
     cy(i) = complex(n-i+1, -(n-i+1))
  end do
  
  call csrot(n, cx, incx, cy, incy, c, s)
  print *, 'Test 1: cx = ', cx
  print *, 'Test 1: cy = ', cy
  
  ! Add more tests if necessary
  
  deallocate(cx, cy)
end program test_csrot

subroutine csrot(n, cx, incx, cy, incy, c, s)
  complex :: cx(*), cy(*), ctemp
  real :: c, s
  integer :: n, incx, incy, i, ix, iy
  
  if (n <= 0) return
  ix = 1
  iy = 1
  if (incx < 0) ix = (-n + 1) * incx + 1
  if (incy < 0) iy = (-n + 1) * incy + 1
  
  if (incx == 1 .and. incy == 1) then
     do i = 1, n
        ctemp = c*cx(i) + s*cy(i)
        cy(i) = c*cy(i) - s*cx(i)
        cx(i) = ctemp
     end do
  else
     do i = 1, n
        ctemp = c*cx(ix) + s*cy(iy)
        cy(iy) = c*cy(iy) - s*cx(ix)
        cx(ix) = ctemp
        ix = ix + incx
        iy = iy + incy
     end do
  end if
end subroutine csrot