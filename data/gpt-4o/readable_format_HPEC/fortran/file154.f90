subroutine evolve(u0, u1, twiddle, d1, d2, d3)



use ft_data
implicit none

integer d1, d2, d3
double complex   u0(d1+1,d2,d3)
double complex   u1(d1+1,d2,d3)
double precision twiddle(d1+1,d2,d3)
integer i, j, k

do k = 1, d3
do j = 1, d2
do i = 1, d1
u0(i,j,k) = u0(i,j,k) * twiddle(i,j,k)
u1(i,j,k) = u0(i,j,k)
end do
end do
end do

return
end
