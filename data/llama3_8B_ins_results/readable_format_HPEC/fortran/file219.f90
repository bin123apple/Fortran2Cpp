subroutine kernel_fdtd_2d(tmax, nx, ny, ex, ey, hz, fict)
implicit none

integer :: tmax, nx, ny
DATA_TYPE, dimension(tmax) :: fict
DATA_TYPE, dimension(ny, nx) :: ex
DATA_TYPE, dimension(ny, nx) :: ey
DATA_TYPE, dimension(ny, nx) :: hz
integer :: i, j, t

!$pragma scop
do t = 1, _PB_TMAX
do j = 1, _PB_NY
ey(j, 1) = fict(t)
end do
do i = 2, _PB_NX
do j = 1, _PB_NY
ey(j, i) = ey(j, i) - (0.5D0 * (hz(j, i) - hz(j, i - 1)))
end do
end do
do i = 1, _PB_NX
do j = 2, _PB_NY
ex(j, i) = ex(j, i) - (0.5D0 * (hz(j, i) - hz(j - 1, i)))
end do
end do
do i = 1, _PB_NX - 1
do j = 1, _PB_NY - 1
hz(j, i) = hz(j, i) - (0.7D0 * (ex(j + 1, i) - ex(j, i)  &
+ ey(j, i + 1) - ey(j, i)))
end do
end do
end do
!$pragma endscop
end subroutine
