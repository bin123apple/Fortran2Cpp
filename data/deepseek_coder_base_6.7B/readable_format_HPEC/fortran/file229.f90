subroutine init_array(n, alpha, a, b)
implicit none

DATA_TYPE, dimension(n, n) :: a
DATA_TYPE, dimension(n, n) :: b
DATA_TYPE :: alpha
integer :: n
integer :: i, j

alpha = 32412D0
do i = 1, n
do j = 1, n
a(j, i) = (DBLE(i - 1) * DBLE(j - 1)) / DBLE(n)
b(j, i) = ((DBLE(i - 1) * DBLE(j - 1))) / DBLE(n)
end do
end do
end subroutine
