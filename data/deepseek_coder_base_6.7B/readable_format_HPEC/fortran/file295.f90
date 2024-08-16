subroutine kernel_bicg(nx, ny, a, s, q, p, r)
implicit none

DATA_TYPE, dimension(ny, nx) :: a
DATA_TYPE, dimension(nx) :: r
DATA_TYPE, dimension(nx) :: q
DATA_TYPE, dimension(ny) :: p
DATA_TYPE, dimension(ny) :: s
integer :: nx,ny
integer :: i,j

!$pragma scop
do i = 1, _PB_NY
s(i) = 0.0D0
end do

do i = 1, _PB_NX
q(i) = 0.0D0
do j = 1, _PB_NY
s(j) = s(j) + (r(i) * a(j, i))
q(i) = q(i) + (a(j, i) * p(j))
end do
end do
!$pragma endscop
end subroutine
