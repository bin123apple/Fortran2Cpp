subroutine init_array(tmax, nx, ny, ex, ey, hz, fict)
implicit none

integer :: nx, ny, tmax
DATA_TYPE, dimension(tmax) :: fict
DATA_TYPE, dimension(ny, nx) :: ex
DATA_TYPE, dimension(ny, nx) :: ey
DATA_TYPE, dimension(ny, nx) :: hz
integer :: i, j
do i = 1, tmax
fict(i) = DBLE(i - 1)
end do
do i = 1, nx
do j = 1, ny
ex(j, i) = (DBLE((i - 1) * (j))) / DBLE(nx)
ey(j, i) = (DBLE((i - 1) * (j + 1))) / DBLE(ny)
hz(j, i) = (DBLE((i - 1) * (j + 2))) / DBLE(nx)
end do
end do
end subroutine
