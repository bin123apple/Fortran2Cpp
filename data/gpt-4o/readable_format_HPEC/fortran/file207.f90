subroutine init_array(n, alpha, beta,  &
a, u1, u2, v1, v2, w, x, y, z)
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
alpha = 43532.0D0
beta = 12313.0D0

do i = 1, n
u1(i) = DBLE(i - 1)
u2(i) = DBLE(i / n) / 2.0D0
v1(i) = DBLE(i / n) / 4.0D0
v2(i) = DBLE(i / n) / 6.0D0
y(i) = DBLE(i / n) / 8.0D0
z(i) = DBLE(i / n) / 9.0D0
x(i) = 0.0D0
w(i) = 0.0D0
do j = 1, n
a(j, i) = ((DBLE(i - 1) * DBLE(j - 1))) / DBLE(n)
end do
end do
end subroutine
