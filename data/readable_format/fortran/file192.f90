! Define the subroutine writerandomfield
subroutine writerandomfield(d, nev, abserr, relerr)
  implicit none
  integer :: i, nev
  real*8 :: d(*), abserr, relerr

  print *, ''
  print *, 'EIGENVALUES OF MODESHAPES OF RANDOMFIELD'
  print *, ''
  do i = nev, 1, -1
     print '(7x,e14.7)', d(i)
  end do

  print *, ''
  print *, 'ABSOLUTE ERROR W.R.T. THE VARIANCE OF THE RANDOMFIELD'
  print *, ''
  print '(7x,e14.7)', abserr
  print *, ''
  print *, 'RELATIVE ERROR W.R.T. THE VARIANCE OF THE RANDOMFIELD'
  print *, ''
  print '(7x,e14.7)', relerr

end subroutine writerandomfield

! Main program starts here
program testRandomFieldWriter
  implicit none
  integer, parameter :: nev = 3
  real*8 :: d(nev) = [0.1d0, 0.2d0, 0.3d0]
  real*8 :: abserr = 0.01d0
  real*8 :: relerr = 0.05d0

  ! Call the subroutine
  call writerandomfield(d, nev, abserr, relerr)
end program testRandomFieldWriter