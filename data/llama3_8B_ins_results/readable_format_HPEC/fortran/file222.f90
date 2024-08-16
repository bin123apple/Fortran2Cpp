subroutine init_array(a, x, nx, ny)
implicit none

double precision :: M_PI
parameter(M_PI = 3.14159265358979323846D0)
DATA_TYPE, dimension(ny, nx) :: a
DATA_TYPE, dimension(ny) :: x
integer :: nx, ny
integer :: i, j
do i = 1, ny
x(i) = DBLE(i - 1) * M_PI
do j = 1, ny
a(j, i) = (DBLE((i - 1) * (j))) / nx
end do
end do
end subroutine
