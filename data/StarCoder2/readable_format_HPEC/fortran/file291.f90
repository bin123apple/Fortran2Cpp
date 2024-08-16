subroutine kernel_seidel(tsteps, n, a)
implicit none

DATA_TYPE, dimension(n, n) :: a
integer :: n, tsteps
integer :: i, t, j

!$pragma scop
do t = 1, _PB_TSTEPS
do i = 2, _PB_N - 1
do j = 2, _PB_N - 1
a(j, i) = (a(j - 1, i - 1) + a(j, i - 1) + a(j + 1, i - 1) + &
a(j - 1, i) + a(j, i) + a(j + 1, i) + &
a(j - 1, i + 1) + a(j, i + 1) + &
a(j + 1, i + 1))/9.0D0
end do
end do
end do
!$pragma endscop
end subroutine
