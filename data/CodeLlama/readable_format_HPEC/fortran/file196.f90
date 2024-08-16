subroutine kernel_trisolv(n , a, x, c)
implicit none

DATA_TYPE, dimension(n, n) :: a
DATA_TYPE, dimension(n) :: c
DATA_TYPE, dimension(n) :: x
integer :: n
integer :: i, j

!$pragma scop
do i = 1, _PB_N
x(i) = c(i)
do j = 1, i - 1
x(i) = x(i) - (a(j, i) * x(j))
end do
x(i) = x(i) / a(i, i)
end do
!$pragma endscop
end subroutine
