subroutine init_array(n, alpha, beta, a, b, x)
implicit none

DATA_TYPE, dimension(n, n) :: a
DATA_TYPE, dimension(n, n) :: b
DATA_TYPE, dimension(n) :: x
DATA_TYPE :: alpha, beta
integer :: n
integer :: i, j

alpha = 43532.0D0
beta = 12313.0D0

do i = 1, n
x(i) = DBLE(i - 1) / DBLE(n)
do j = 1, n
a(j, i) = ((DBLE(i - 1) * DBLE(j - 1))) / DBLE(n)
b(j, i) = ((DBLE(i - 1) * DBLE(j - 1))) / DBLE(n)
end do
end do
end subroutine
