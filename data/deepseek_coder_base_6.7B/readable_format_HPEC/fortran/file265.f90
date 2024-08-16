subroutine kernel_jacobi_2d_imper(tsteps, n, a, b)
implicit none

DATA_TYPE, dimension(n, n) :: a
DATA_TYPE, dimension(n, n) :: b
integer :: n, tsteps
integer :: i, j, t

!$pragma scop
do t = 1, _PB_TSTEPS
do i = 2, _PB_N - 1
do j = 2, _PB_N - 1
b(j, i) = 0.2D0 * (a(j, i) + a(j - 1, i) + a(1 + j, i) + &
a(j, 1 + i) + a(j, i - 1))
end do
end do
do i = 2, _PB_N - 1
do j = 2, _PB_N - 1
a(j, i) = b(j, i)
end do
end do
end do
!$pragma endscop
end subroutine
