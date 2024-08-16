subroutine init_array(n, a, x, c)
implicit none

DATA_TYPE, dimension(n, n) :: a
DATA_TYPE, dimension(n) :: c
DATA_TYPE, dimension(n) :: x
integer :: n
integer :: i, j
do i = 1, n
c(i) = DBLE(i - 1) / DBLE(n)
x(i) = DBLE(i - 1) / DBLE(n)
do j = 1, n
a(j, i) = (DBLE(i - 1) * DBLE(j - 1)) / DBLE(n)
end do
end do
end subroutine
