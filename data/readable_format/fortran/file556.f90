! op.f90
subroutine op(n,x,y,ad,au,jq,irow)
  implicit none
  integer, intent(in) :: n, jq(*), irow(*)
  real*8, intent(in) :: x(*), au(*), ad(*)
  real*8, intent(inout) :: y(*)
  integer :: j, l, i
  
  do i=1,n
     y(i)=ad(i)*x(i)
  enddo
  do j=1,n
     do l=jq(j),jq(j+1)-1
        i=irow(l)
        y(i)=y(i)+au(l)*x(j)
        y(j)=y(j)+au(l)*x(i)
     enddo
  enddo
end subroutine op

program test_op
  implicit none
  integer, parameter :: n = 4
  real*8 :: x(n) = [1.0, -2.0, 3.0, -4.0]
  real*8 :: y(n) = [0.0, 0.0, 0.0, 0.0]
  real*8 :: ad(n) = [1.0, 2.0, 3.0, 4.0]
  real*8 :: au(5) = [5.0, 6.0, 7.0, 8.0, 9.0]
  integer :: jq(n+1) = [1, 3, 4, 5, 6]
  integer :: irow(5) = [2, 4, 1, 3, 2]

  call op(n, x, y, ad, au, jq, irow)
  
  print *, "Results for y:"
  print *, y
end program test_op