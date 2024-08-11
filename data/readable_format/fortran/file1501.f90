! sphcover.f90
subroutine sphcover(n, tp)
  implicit none
  integer, intent(in) :: n
  real(8), intent(out) :: tp(2,n)
  integer :: k
  real(8), parameter :: pi=3.1415926535897932385d0
  real(8) :: z,dz,p,dp
  
  if (n.le.0) then
    print *, "Error(sphcover): n <= 0 :", n
    stop
  end if
  
  dz=2.d0/dble(n)
  z=1.d0-dz/2.d0
  tp(1,1)=acos(z)
  dp=pi*(3.d0-sqrt(5.d0))
  p=0.d0
  tp(2,1)=p
  
  do k=2,n
    z=z-dz
    tp(1,k)=acos(z)
    p=p+dp
    tp(2,k)=mod(p,2.d0*pi)
  end do
end subroutine

program test_sphcover
  implicit none
  integer, parameter :: n = 10
  real(8) :: tp(2,n)
  integer :: i
  
  call sphcover(n, tp)
  
  do i = 1, n
    print *, 'Point ', i, ': Theta = ', tp(1,i), ', Phi = ', tp(2,i)
  end do
end program