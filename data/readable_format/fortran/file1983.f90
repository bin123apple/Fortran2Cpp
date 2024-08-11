program testLinInterp
  implicit none
  integer, parameter :: n1 = 5, n2 = 10
  real, dimension(n1) :: x1 = [1.0, 2.0, 3.0, 4.0, 5.0]
  real, dimension(n1) :: y1 = [1.0, 2.0, 3.0, 4.0, 5.0]
  real, dimension(n2) :: x2 = [1.5, 2.5, 3.5, 4.5, 1.1, 2.2, 3.3, 4.4, 5.0, 5.5]
  real, dimension(n2) :: y2
  integer :: i

  call lininterp(n1, x1, y1, n2, x2, y2)

  print *, 'Interpolated values:'
  do i = 1, n2
     print '("x2(",I1,") = ",F4.1,", y2(",I1,") = ",F4.1)', i, x2(i), i, y2(i)
  end do

contains

  subroutine lininterp(n1, x1, y1, n2, x2, y2)
    integer, intent(in) :: n1, n2
    real, dimension(n1), intent(in) :: x1, y1
    real, dimension(n2), intent(in) :: x2
    real, dimension(n2), intent(out) :: y2
    integer :: i1, j2, j

    i1 = 1
    j2 = 1

    do while (j2 <= n2)
      if (x2(j2) < x1(i1)) then
         y2(j2) = y1(i1)
         j2 = j2+1
         cycle
      end if

      if (x2(j2) > x1(i1)) then
         if (i1 < n1) then
            if (x2(j2) <= x1(i1+1)) then
               y2(j2) = xinterp(x1(i1), x1(i1+1), y1(i1), y1(i1+1), x2(j2))
               j2 = j2 + 1
               if (j2 > n2) exit
            else
               i1 = i1 + 1
            end if
         else
            exit
         end if
      else
         j2 = j2+1
      end if
    end do

    do j = j2, n2
       y2(j) = y1(n1)
    end do
  end subroutine lininterp

  function xinterp(x1, x2, y1, y2, xval) result(yval)
    real, intent(in) :: x1, x2, y1, y2, xval
    real :: yval

    if (xval <= x1) then
       yval = y1
    else if (xval >= x2) then
       yval = y2
    else if (x2 == x1) then
       yval = (y1 + y2) / 2.0
    else
       yval = y1 + (y2 - y1) * (xval - x1) / (x2 - x1)
    end if
  end function xinterp

end program testLinInterp