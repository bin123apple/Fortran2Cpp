subroutine kernel_ludcmp(n, a, b, x, y)
implicit none

DATA_TYPE, dimension(n + 1, n + 1) :: a
DATA_TYPE, dimension(n + 1) :: x
DATA_TYPE, dimension(n + 1) :: b
DATA_TYPE, dimension(n + 1) :: y
DATA_TYPE :: w
integer :: n
integer :: i, j, k

!$pragma scop
b(1) = 1.0D0
do i = 1, _PB_N
do j = i + 1, _PB_N + 1
w = a(i, j)
do k = 1, i - 1
w = w - (a(k, j) * a(i, k))
end do
a(i, j) = w / a(i, i)
end do
do j = i + 1, _PB_N + 1
w = a(j, i + 1)
do k = 1, i
w = w - (a(k, i + 1) * a(j, k))
end do
a(j, i + 1) = w
end do
end do
y(1) = b(1)
do i = 2, _PB_N + 1
w = b(i)
do j = 1, i - 1
w = w - (a(j, i) * y(j))
end do
y(i) = w
end do
x(_PB_N + 1) = y(_PB_N + 1) / a(_PB_N + 1, _PB_N + 1)
do i = 1, _PB_N
w = y(_PB_N + 1 - i)
do j = _PB_N + 2 - i, _PB_N + 1
w = w - (a(j, _PB_N + 1 - i) * x(j))
end do
x(_PB_N + 1 - i) = w / a(_PB_N + 1 - i, _PB_N + 1 - i)
end do
!$pragma endscop
end subroutine
