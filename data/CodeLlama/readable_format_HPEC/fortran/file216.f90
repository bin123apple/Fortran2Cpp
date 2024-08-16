subroutine kernel_jacobi1d(tsteps, n, a, b)
implicit none

DATA_TYPE, dimension(n) :: a
DATA_TYPE, dimension(n) :: b
integer :: n, tsteps
integer :: i, t, j
!$pragma scop
do t = 1, _PB_TSTEPS
do i = 2, _PB_N - 1
b(i) = 0.33333D0 * (a(i - 1) + a(i) + a(i + 1))
end do

do j = 2, _PB_N -1
a(j) = b(j)
end do
end do
!$pragma endscop
end subroutine
