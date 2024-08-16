subroutine kernel_cholesky(n, p, a)
implicit none

DATA_TYPE, dimension(n, n) :: a
DATA_TYPE, dimension(n) :: p
DATA_TYPE :: x
integer :: n
integer :: i, j, k

!$pragma scop
do i = 1, _PB_N
x = a(i, i)
do j = 1, i - 1
x = x - a(j, i) * a(j, i)
end do
p(i) = 1.0D0 / sqrt(x)
do j = i + 1, _PB_N
x = a(j, i)
do k = 1, i - 1
x = x - (a(k, j) * a(k, i))
end do
a(i, j) = x * p(i)
end do
end do
!$pragma endscop
end subroutine
