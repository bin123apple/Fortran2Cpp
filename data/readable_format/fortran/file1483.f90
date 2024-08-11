! mysubs.f90
subroutine mysub
  print *, 'Printing this requires Fortran language libraries'
end subroutine

subroutine my_sub
end subroutine

! Test harness
program test
  call mysub
  call my_sub
end program test