module my_functions
  implicit none
  contains

  ! Define the damaxf function within a module
  REAL*8 function damaxf(n, dx, incx)
    implicit none
    double precision, intent(in) :: dx(*)
    integer, intent(in) :: n, incx
    integer :: i, ix
    double precision :: dtemp

    damaxf = 0.0d0
    if (n < 1 .or. incx <= 0) return

    damaxf = abs(dx(1))
    if (incx == 1) then
      do i = 2, n
        dtemp = abs(dx(i))
        if (dtemp > damaxf) then
          damaxf = dtemp
        endif
      end do
    else
      ix = 1
      do i = 2, n
        ix = ix + incx
        dtemp = abs(dx(ix))
        if (dtemp > damaxf) then
          damaxf = dtemp
        endif
      end do
    endif
  end function damaxf
end module my_functions

program test_damaxf
  use my_functions
  implicit none
  double precision, allocatable :: dx(:)
  integer :: n, incx
  double precision :: result

  ! Test 1
  n = 5
  incx = 1
  allocate(dx(n))
  dx = [1.0d0, -2.0d0, 3.0d0, -4.0d0, 5.0d0]
  result = damaxf(n, dx, incx)
  print *, "Test 1: Expected 5, got ", result

  ! Test 2
  n = 3
  incx = 2
  dx = [1.0d0, 3.0d0, -7.0d0, 2.0d0, 9.0d0]
  result = damaxf(n, dx, incx)
  print *, "Test 2: Expected 9, got ", result

  ! Test 3
  n = 0
  incx = 1
  result = damaxf(n, dx, incx)
  print *, "Test 3: Expected 0, got ", result

  deallocate(dx)
end program test_damaxf