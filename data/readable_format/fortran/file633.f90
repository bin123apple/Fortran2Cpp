! Define the dscal subroutine
subroutine dscal(n, da, dx, incx)
  double precision da, dx(*)
  integer i, incx, m, mp1, n, nincx

  if(n.le.0 .or. incx.le.0) return
  if(incx.eq.1) go to 20

  nincx = n*incx
  do 10 i = 1, nincx, incx
    dx(i) = da*dx(i)
10 continue
  return

20 m = mod(n, 5)
  if(m.eq.0) go to 40
  do 30 i = 1, m
    dx(i) = da*dx(i)
30 continue
  if(n.lt.5) return
40 mp1 = m + 1
  do 50 i = mp1, n, 5
    dx(i) = da*dx(i)
    dx(i + 1) = da*dx(i + 1)
    dx(i + 2) = da*dx(i + 2)
    dx(i + 3) = da*dx(i + 3)
    dx(i + 4) = da*dx(i + 4)
50 continue
  return
end

! Test program for dscal
program test_dscal
  implicit none
  double precision :: da
  integer :: incx, n, i
  double precision, allocatable :: dx(:)

  ! Test 1: Basic functionality
  n = 5
  allocate(dx(n))
  dx = (/1.0, 2.0, 3.0, 4.0, 5.0/)
  da = 2.0
  incx = 1
  call dscal(n, da, dx, incx)
  print *, "Test 1: dx = ", dx
  
  ! Test 2: Non-unit increment
  n = 6
  allocate(dx(n))
  dx = (/1.0, 2.0, 3.0, 4.0, 5.0, 6.0/)
  da = 3.0
  incx = 2
  call dscal(n, da, dx, incx)
  print *, "Test 2: dx = ", dx
  
  ! Test 3: Edge case with n <= 0
  n = 0
  da = 2.0
  incx = 1
  call dscal(n, da, dx, incx)
  print *, "Test 3: Should not modify dx, dx = ", dx

  ! Clean up
  deallocate(dx)

end program test_dscal