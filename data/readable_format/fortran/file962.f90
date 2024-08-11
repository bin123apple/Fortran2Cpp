! combined.f90
module mod_setprecision
  implicit none
  integer, parameter :: sprec = kind(1.0)
  integer, parameter :: dprec = kind(1.0d0)
end module mod_setprecision

program test_mod_setprecision
  use mod_setprecision
  implicit none

  ! Test for single precision
  if (sprec .eq. kind(1.0)) then
    print *, "Test for single precision (sprec) passed."
  else
    print *, "Test for single precision (sprec) failed."
  endif

  ! Test for double precision
  if (dprec .eq. kind(1.0d0)) then
    print *, "Test for double precision (dprec) passed."
  else
    print *, "Test for double precision (dprec) failed."
  endif
end program test_mod_setprecision