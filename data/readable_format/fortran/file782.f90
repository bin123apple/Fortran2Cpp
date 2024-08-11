program test_norshell3
  implicit none
  double precision xl(3,3), xnor(3)
  double precision xi, et
  integer i

  ! Test data
  xi = 0.0
  et = 0.0
  xl(1,1) = 1.0
  xl(1,2) = 2.0
  xl(1,3) = 3.0
  xl(2,1) = 4.0
  xl(2,2) = 5.0
  xl(2,3) = 6.0
  xl(3,1) = 7.0
  xl(3,2) = 8.0
  xl(3,3) = 9.0

  call norshell3(xi, et, xl, xnor)

  ! Output result for verification
  do i = 1, 3
     write(*,*) 'xnor(', i, ') = ', xnor(i)
  end do
end program test_norshell3

subroutine norshell3(xi,et,xl,xnor)
  implicit none
  integer i,j,k
  double precision shp(2,3),xs(3,2),xl(3,3),xnor(3)
  double precision xi,et
  shp(1,1)=-1.d0
  shp(1,2)=1.d0
  shp(1,3)=0.d0
  shp(2,1)=-1.d0
  shp(2,2)=0.d0
  shp(2,3)=1.d0
  do i=1,3
    do j=1,2
      xs(i,j)=0.d0
      do k=1,3
        xs(i,j)=xs(i,j)+xl(i,k)*shp(j,k)
      enddo
    enddo
  enddo
  xnor(1)=xs(2,1)*xs(3,2)-xs(3,1)*xs(2,2)
  xnor(2)=xs(3,1)*xs(1,2)-xs(1,1)*xs(3,2)
  xnor(3)=xs(1,1)*xs(2,2)-xs(2,1)*xs(1,2)
  return
end subroutine norshell3