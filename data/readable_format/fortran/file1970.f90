program test_norshell8
  implicit none
  integer :: i
  double precision :: xi, et
  double precision, dimension(3,8) :: xl
  double precision, dimension(3) :: xnor

  ! Example inputs
  xi = 0.5
  et = -0.25
  xl = reshape((/(i, i=1,24)/), shape(xl))

  ! Call the subroutine
  call norshell8(xi, et, xl, xnor)

  ! Print the result to compare
  print *, 'xnor:'
  print *, xnor

contains

  subroutine norshell8(xi,et,xl,xnor)
    implicit none
    integer i,j,k
    double precision shp(4,8),xs(3,2),xl(3,8),xnor(3)
    double precision xi,et
    shp(1,1)=(1.d0-et)*(2.d0*xi+et)/4.d0
    shp(1,2)=(1.d0-et)*(2.d0*xi-et)/4.d0
    shp(1,3)=(1.d0+et)*(2.d0*xi+et)/4.d0
    shp(1,4)=(1.d0+et)*(2.d0*xi-et)/4.d0
    shp(1,5)=-xi*(1.d0-et)
    shp(1,6)=(1.d0-et*et)/2.d0
    shp(1,7)=-xi*(1.d0+et)
    shp(1,8)=-(1.d0-et*et)/2.d0
    shp(2,1)=(1.d0-xi)*(2.d0*et+xi)/4.d0
    shp(2,2)=(1.d0+xi)*(2.d0*et-xi)/4.d0
    shp(2,3)=(1.d0+xi)*(2.d0*et+xi)/4.d0
    shp(2,4)=(1.d0-xi)*(2.d0*et-xi)/4.d0
    shp(2,5)=-(1.d0-xi*xi)/2.d0
    shp(2,6)=-et*(1.d0+xi)
    shp(2,7)=(1.d0-xi*xi)/2.d0
    shp(2,8)=-et*(1.d0-xi)
    do i=1,3
      do j=1,2
        xs(i,j)=0.d0
        do k=1,8
          xs(i,j)=xs(i,j)+xl(i,k)*shp(j,k)
        enddo
      enddo
    enddo
    xnor(1)=xs(2,1)*xs(3,2)-xs(3,1)*xs(2,2)
    xnor(2)=xs(1,2)*xs(3,1)-xs(3,2)*xs(1,1)
    xnor(3)=xs(1,1)*xs(2,2)-xs(2,1)*xs(1,2)
    return
  end subroutine norshell8

end program test_norshell8