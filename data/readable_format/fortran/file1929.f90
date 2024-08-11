module a
  implicit none
contains
  real function d (i)
    real, intent(in) :: i
    real :: c
    integer :: j
    d = 1.0
    return
  end function d

  real function c (j)
    real :: i
    integer, intent(in) :: j
    c = 2.0
    return
  end function c

  real function e (i)
    real, intent(in) :: i
    real :: f
    integer :: j
    e = 3.0
    return
  end function e

  real function f (j)
    real :: i
    integer, intent(in) :: j
    f = 4.0
    return
  end function f
end module a

program test
  use a
  implicit none

  if (d(1.0) .ne. 1.0) then
    print *, "Test d failed"
    stop
  end if

  if (c(1) .ne. 2.0) then
    print *, "Test c failed"
    stop
  end if

  if (e(1.0) .ne. 3.0) then
    print *, "Test e failed"
    stop
  end if

  if (f(1) .ne. 4.0) then
    print *, "Test f failed"
    stop
  end if

  print *, "All Fortran tests passed."
end program test