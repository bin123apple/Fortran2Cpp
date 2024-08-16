subroutine setbv



use lu_data
implicit none

integer i, j, k, m
double precision temp1(5), temp2(5)

do j = 1, ny
do i = 1, nx
call exact( i, j, 1, temp1 )
call exact( i, j, nz, temp2 )
do m = 1, 5
u( m, i, j, 1 ) = temp1(m)
u( m, i, j, nz ) = temp2(m)
end do
end do
end do

do k = 1, nz
do i = 1, nx
call exact( i, 1, k, temp1 )
call exact( i, ny, k, temp2 )
do m = 1, 5
u( m, i, 1, k ) = temp1(m)
u( m, i, ny, k ) = temp2(m)
end do
end do
end do

do k = 1, nz
do j = 1, ny
call exact( 1, j, k, temp1 )
call exact( nx, j, k, temp2 )
do m = 1, 5
u( m, 1, j, k ) = temp1(m)
u( m, nx, j, k ) = temp2(m)
end do
end do
end do

return
end
