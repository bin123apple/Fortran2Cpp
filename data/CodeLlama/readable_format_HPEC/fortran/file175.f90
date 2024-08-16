subroutine compute_initial_conditions(u0, d1, d2, d3)



use ft_data
implicit none

integer d1, d2, d3
double complex u0(d1+1, d2, d3)
integer k, j
double precision x0, start, an, dummy, starts(nz)


start = seed
call ipow46(a, 0, an)
dummy = randlc(start, an)
call ipow46(a, 2*nx*ny, an)

starts(1) = start
do k = 2, dims(3)
dummy = randlc(start, an)
starts(k) = start
end do

do k = 1, dims(3)
x0 = starts(k)
do j = 1, dims(2)
call vranlc(2*nx, x0, a, u0(1, j, k))
end do
end do

return
end
