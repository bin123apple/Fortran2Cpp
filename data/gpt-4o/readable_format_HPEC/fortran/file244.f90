subroutine kernel_atax(nx, ny, a, x, y, tmp)
implicit none

DATA_TYPE, dimension(ny, nx) :: a
DATA_TYPE, dimension(ny) :: x
DATA_TYPE, dimension(ny) :: y
DATA_TYPE, dimension(nx) :: tmp
integer nx, ny, i, j

!$pragma scop
do i = 1, _PB_NY
y(i) = 0.0D0
end do

do i = 1, _PB_NX
tmp(i) = 0.0D0
do j = 1, _PB_NY
tmp(i) = tmp(i) + (a(j, i) * x(j))
end do
do j = 1, _PB_NY
y(j) = y(j) + a(j, i) * tmp(i)
end do
end do
!$pragma endscop
end subroutine
