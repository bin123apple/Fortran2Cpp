program test_cswap
  implicit none
  complex, dimension(5) :: cx, cy
  integer :: i

  ! Initialize arrays
  do i = 1, 5
     cx(i) = complex(i, i)
     cy(i) = complex(-i, -i)
  end do

  ! Call the cswap subroutine
  call cswap(5, cx, 1, cy, 1)

  ! Output results
  print *, 'After swapping:'
  print *, 'cx:'
  do i = 1, 5
     print *, cx(i)
  end do
  print *, 'cy:'
  do i = 1, 5
     print *, cy(i)
  end do

contains

  subroutine cswap (n, cx, incx, cy, incy)
    ! Declare variable types
    integer :: n, incx, incy, i, ix, iy
    complex :: cx(*), cy(*), ctemp

    if (n <= 0) return
    if (incx == 1 .and. incy == 1) then
      do i = 1, n
        ctemp = cx(i)
        cx(i) = cy(i)
        cy(i) = ctemp
      end do
      return
    end if

    ix = 1
    iy = 1
    if (incx < 0) ix = (-n + 1) * incx + 1
    if (incy < 0) iy = (-n + 1) * incy + 1
    do i = 1, n
      ctemp = cx(ix)
      cx(ix) = cy(iy)
      cy(iy) = ctemp
      ix = ix + incx
      iy = iy + incy
    end do
    return
  end subroutine cswap

end program test_cswap