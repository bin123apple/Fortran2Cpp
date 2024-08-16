subroutine init_array(n, a, b, x, y)
implicit none

DATA_TYPE, dimension(n + 1, n + 1) :: a
DATA_TYPE, dimension(n + 1) :: x
DATA_TYPE, dimension(n + 1) :: b
DATA_TYPE, dimension(n + 1) :: y
integer :: n
integer :: i, j

do i = 1, n  + 1
x(i) = DBLE(i)
y(i) = (i/n/2.0D0) + 1.0D0
b(i) = (i/n/2.0D0) + 42.0D0
do j = 1, n + 1
a(j, i) = (DBLE(i) * DBLE(j)) / DBLE(n)
end do
end do
end subroutine
