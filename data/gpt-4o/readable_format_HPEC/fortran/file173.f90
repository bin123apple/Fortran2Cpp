subroutine comm3(u,n1,n2,n3,kk)



use mg_data
implicit none

integer n1, n2, n3, kk
double precision u(n1,n2,n3)
integer i1, i2, i3

if (timeron) call timer_start(T_comm3)
do  i3=2,n3-1
do  i2=2,n2-1
u( 1,i2,i3) = u(n1-1,i2,i3)
u(n1,i2,i3) = u(   2,i2,i3)
enddo

do  i1=1,n1
u(i1, 1,i3) = u(i1,n2-1,i3)
u(i1,n2,i3) = u(i1,   2,i3)
enddo
enddo

do  i2=1,n2
do  i1=1,n1
u(i1,i2, 1) = u(i1,i2,n3-1)
u(i1,i2,n3) = u(i1,i2,   2)
enddo
enddo
if (timeron) call timer_stop(T_comm3)

return
end
