subroutine init_array(n, x1, x2, y1, y2, a)
implicit none

DATA_TYPE, dimension(n, n) :: a
DATA_TYPE, dimension(n) :: x1
DATA_TYPE, dimension(n) :: y1
DATA_TYPE, dimension(n) :: x2
DATA_TYPE, dimension(n) :: y2
integer :: n
integer :: i, j

do i = 1, n
x1(i) = DBLE(i - 1) / DBLE(n)
x2(i) = (DBLE(i - 1) + 1.0D0) / DBLE(n)
y1(i) = (DBLE(i - 1) + 3.0D0) / DBLE(n)
y2(i) = (DBLE(i - 1) + 4.0D0) / DBLE(n)
do j = 1, n
a(j, i) = ((DBLE(i - 1) * DBLE(j - 1))) / DBLE(n)
end do
end do
end subroutine
