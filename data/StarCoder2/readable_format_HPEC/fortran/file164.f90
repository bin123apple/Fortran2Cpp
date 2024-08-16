subroutine conj_grad ( rnorm )


use cg_data
implicit none

integer   j
integer   cgit, cgitmax
integer(kz) k

double precision   d, sum, rho, rho0, alpha, beta, rnorm, suml

data      cgitmax / 25 /


rho = 0.0d0
sum = 0.0d0


do j=1,naa+1
q(j) = 0.0d0
z(j) = 0.0d0
r(j) = x(j)
p(j) = r(j)
enddo


do j=1, lastcol-firstcol+1
rho = rho + r(j)*r(j)
enddo

do cgit = 1, cgitmax

rho0 = rho
d = 0.d0
rho = 0.d0

do j=1,lastrow-firstrow+1
suml = 0.d0
do k=rowstr(j),rowstr(j+1)-1
suml = suml + a(k)*p(colidx(k))
enddo
q(j) = suml
enddo




do j=1, lastcol-firstcol+1
d = d + p(j)*q(j)
enddo


alpha = rho0 / d

do j=1, lastcol-firstcol+1
z(j) = z(j) + alpha*p(j)
r(j) = r(j) - alpha*q(j)

rho = rho + r(j)*r(j)
enddo

beta = rho / rho0

do j=1, lastcol-firstcol+1
p(j) = r(j) + beta*p(j)
enddo


enddo                             ! end of do cgit=1,cgitmax


do j=1,lastrow-firstrow+1
suml = 0.d0
do k=rowstr(j),rowstr(j+1)-1
suml = suml + a(k)*z(colidx(k))
enddo
r(j) = suml
enddo


do j=1, lastcol-firstcol+1
suml = x(j) - r(j)
sum  = sum + suml*suml
enddo

rnorm = sqrt( sum )



return
end
