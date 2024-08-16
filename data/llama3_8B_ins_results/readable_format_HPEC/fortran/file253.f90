subroutine kernel_gesummv(n, alpha, beta, &
a, b, tmp, x, y)
implicit none

DATA_TYPE, dimension(n, n) :: a
DATA_TYPE, dimension(n, n) :: b
DATA_TYPE, dimension(n) :: x, y, tmp
DATA_TYPE :: alpha, beta
integer :: n
integer :: i, j

!$pragma scop
do i = 1, _PB_N
tmp(i) = 0.0D0
y(i) = 0.0D0
do j = 1, _PB_N
tmp(i) = (a(j, i) * x(j)) + tmp(i)
y(i) = (b(j, i) * x(j)) + y(i)
end do
y(i) = (alpha * tmp(i)) + (beta * y(i))
end do
!$pragma endscop
end subroutine
