subroutine init_array(nx, ny, a, r, p)
implicit none

double precision :: M_PI
parameter(M_PI = 3.14159265358979323846D0)
DATA_TYPE, dimension(ny, nx) :: a
DATA_TYPE, dimension(nx) :: r
DATA_TYPE, dimension(ny) :: p
integer :: nx, ny
integer :: i, j

do i = 1, ny
p(i) = DBLE(i - 1) * M_PI
end do

do i = 1, nx
r(i) = DBLE(i - 1) * M_PI
do j = 1, ny
a(j, i) = (DBLE(i - 1) * DBLE(j)) / nx
end do
end do
end subroutine
