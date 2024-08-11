program test_dsum
  implicit none
  
  ! Test program and dsum function are in the same file
  
  ! Declaration of external dsum function removed since it's now defined in this file
  
  double precision, allocatable :: dx(:)
  integer :: n, incx
  double precision :: result

  ! Test 1
  n = 10
  incx = 1
  allocate(dx(n))
  dx = (/1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0, 6.0d0, 7.0d0, 8.0d0, 9.0d0, 10.0d0/)
  result = dsum(n, dx, incx)
  print *, "Test 1 (n=10, incx=1): ", result

  ! Test 2
  n = 6
  incx = 2
  allocate(dx(n))
  dx = (/1.0d0, -1.0d0, 2.0d0, -2.0d0, 3.0d0, -3.0d0/)
  result = dsum(n, dx, incx)
  print *, "Test 2 (n=6, incx=2): ", result

  ! Test 3
  n = 3
  incx = 3
  allocate(dx(n))
  dx = (/1.0d0, 100.0d0, -50.0d0/)
  result = dsum(n, dx, incx)
  print *, "Test 3 (n=3, incx=3): ", result

  ! Clean up
  deallocate(dx)
  
contains

  ! dsum function definition
  double precision function dsum(n, dx, incx)
    integer, intent(in) :: n, incx
    double precision, intent(in) :: dx(*)
    double precision :: dtemp
    integer :: i, m, mp1, nincx

    dsum = 0.0d0
    dtemp = 0.0d0
    if (n <= 0 .or. incx <= 0) return
    if (incx == 1) goto 20

    nincx = n*incx
    do i = 1, nincx, incx
      dtemp = dtemp + dx(i)
    end do
    dsum = dtemp
    return

 20 m = mod(n, 6)
    if (m /= 0) then
      do i = 1, m
        dtemp = dtemp + dx(i)
      end do
      if (n < 6) goto 60
    end if
 40 mp1 = m + 1
    do i = mp1, n, 6
      dtemp = dtemp + dx(i) + dx(i+1) + dx(i+2) + dx(i+3) + dx(i+4) + dx(i+5)
    end do
 60 dsum = dtemp
    return
  end function dsum

end program test_dsum