PROGRAM main
  implicit none

  real   :: xx,yy,zz

  xx=10.
  zz=15.678e0

  call test(xx,yy,zz)
  
  print*, 'xx= ', xx, ' yy= ', yy, ' zz= ', zz

  ! Unit test
  if (yy == 190.0 .and. zz == 19.0) then
    print*, 'Test passed.'
  else
    print*, 'Test failed.'
  endif

CONTAINS
  SUBROUTINE test(x,y,z)
    implicit none
  
    real, intent(in)    :: x
    real, intent(out)   :: y
    real, intent(inout) :: z
  
    z=19
    y=z*x
  
  END SUBROUTINE test
END PROGRAM main