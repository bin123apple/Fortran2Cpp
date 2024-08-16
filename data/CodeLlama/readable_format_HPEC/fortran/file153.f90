subroutine l2norm ( ldx, ldy, ldz,  &
&                    nx0, ny0, nz0,  &
&                    ist, iend,  &
&                    jst, jend,  &
&                    v, sum )


implicit none

integer ldx, ldy, ldz
integer nx0, ny0, nz0
integer ist, iend
integer jst, jend
double precision  v(5,ldx/2*2+1,ldy/2*2+1,*), sum(5)

integer i, j, k, m


do m = 1, 5
sum(m) = 0.0d+00
end do

do k = 2, nz0-1
do j = jst, jend
do i = ist, iend
do m = 1, 5
sum(m) = sum(m) + v(m,i,j,k)*v(m,i,j,k)
end do
end do
end do
end do

do m = 1, 5
sum(m) = sqrt ( sum(m) / ( dble(nx0-2)*(ny0-2)*(nz0-2) ) )
end do

return
end
