subroutine init_array(n, x, a, b)
implicit none

DATA_TYPE, dimension(n, n) :: a
DATA_TYPE, dimension(n, n) :: x
DATA_TYPE, dimension(n, n) :: b
integer :: n
integer :: i, j

do i = 1, n
do j = 1, n
x(j, i) = (DBLE((i - 1) * (j)) + 1.0D0) / DBLE(n)
a(j, i) = (DBLE((i - 1) * (j + 1)) + 2.0D0) / DBLE(n)
b(j, i) = (DBLE((i - 1) * (j + 2)) + 3.0D0) / DBLE(n)
end do
end do
end subroutine
