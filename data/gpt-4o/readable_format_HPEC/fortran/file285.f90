subroutine norm2u3(r,n1,n2,n3,rnm2,rnmu,nx,ny,nz)


use mg_data, only : timeron

implicit none

integer n1, n2, n3, nx, ny, nz
double precision rnm2, rnmu, r(n1,n2,n3)
double precision s, a
integer i3, i2, i1

double precision dn

integer T_norm2
parameter (T_norm2=9)

if (timeron) call timer_start(T_norm2)
dn = 1.0d0*nx*ny*nz

s=0.0D0
rnmu = 0.0D0
do  i3=2,n3-1
do  i2=2,n2-1
do  i1=2,n1-1
s=s+r(i1,i2,i3)**2
a=abs(r(i1,i2,i3))
rnmu=dmax1(rnmu,a)
enddo
enddo
enddo

rnm2=sqrt( s / dn )
if (timeron) call timer_stop(T_norm2)

return
end
