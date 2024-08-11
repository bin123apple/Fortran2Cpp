subroutine writeTurnDirections(xn, turdir, nev, nm)
  implicit none
  character(len=*), intent(in) :: turdir
  integer, intent(in) :: nev, nm
  real*8, intent(in) :: xn(3)
  integer :: j

  print *, ''
  print *, '    E I G E N M O D E   T U R N I N G   D I R E C T I O N'
  print *, ''
  print '(A,3(1X,E11.4))', '    Axis reference direction:', xn
  print *, ''
  print *, ' NODAL   MODE NO     TURNING DIRECTION (F=FORWARD,B=BACKWARD)'
  print *, 'DIAMETER'
  print *, ''
  do j = 1, nev
     print '(I5,4X,I7,10X,A1)', nm, j, turdir(j:j)
  end do
end subroutine

program test
  implicit none
  character(len=3) :: turdir = 'FBF'
  integer :: nev, nm
  real*8 :: xn(3) = [1.23, 4.56, 7.89]
  nev = 3
  nm = 1

  call writeTurnDirections(xn, turdir, nev, nm)
end program test