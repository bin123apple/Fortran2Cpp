subroutine kernel_gemver(n, alpha, beta,  &
a, u1, v1, u2, v2, &
w, x, y, z)
implicit none

DATA_TYPE, dimension(n, n) :: a
DATA_TYPE, dimension(n) :: u1
DATA_TYPE, dimension(n) :: u2
DATA_TYPE, dimension(n) :: v1
DATA_TYPE, dimension(n) :: v2
DATA_TYPE, dimension(n) :: w
DATA_TYPE, dimension(n) :: x
DATA_TYPE, dimension(n) :: y
DATA_TYPE, dimension(n) :: z
DATA_TYPE :: alpha, beta
integer :: n
integer :: i, j

!$pragma scop
do i = 1, _PB_N
do j = 1, _PB_N
a(j, i) = a(j, i) + (u1(i) * v1(j)) + (u2(i) * v2(j))
end do
end do
do i = 1, _PB_N
do j = 1, _PB_N
x(i) = x(i) + (beta * a(i, j) * y(j))
end do
end do
do i = 1, _PB_N
x(i) = x(i) + z(i)
end do
do i = 1, _PB_N
do j = 1, _PB_N
w(i) = w(i) + (alpha * a(j, i) * x(j))
end do
end do
!$pragma endscop
end subroutine
