! Declare the dscal subroutine
subroutine dscal(n, da, dx, incx)
  implicit none
  integer, intent(in) :: n, incx
  double precision, intent(in) :: da
  double precision, intent(inout) :: dx(*)
  integer :: i, m, mp1, nincx

  if (n <= 0 .or. incx <= 0) return
  if (incx == 1) then
    m = mod(n, 5)
    if (m /= 0) then
      do i = 1, m
        dx(i) = da * dx(i)
      end do
      if (n < 5) return
    end if
    mp1 = m + 1
    do i = mp1, n, 5
      dx(i) = da * dx(i)
      dx(i + 1) = da * dx(i + 1)
      dx(i + 2) = da * dx(i + 2)
      dx(i + 3) = da * dx(i + 3)
      dx(i + 4) = da * dx(i + 4)
    end do
  else
    nincx = n*incx
    do i = 1, nincx, incx
      dx(i) = da * dx(i)
    end do
  end if
end subroutine dscal

! Test program for dscal
program testDscal
  implicit none
  double precision, allocatable :: dx(:)
  double precision :: da
  integer :: n, incx, i

  ! Initialize test parameters
  n = 5
  da = 2.0
  incx = 1
  allocate(dx(n))
  dx = (/1.0, 2.0, 3.0, 4.0, 5.0/)

  ! Perform the scaling operation
  call dscal(n, da, dx, incx)

  ! Output results to verify correctness
  print *, "Results after scaling: "
  do i = 1, n
    print *, 'dx(', i, ') = ', dx(i)
  end do

  ! Cleanup
  deallocate(dx)
end program testDscal