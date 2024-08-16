subroutine kernel_mvt(n, x1, x2, y1, y2, a)
implicit none

DATA_TYPE, dimension(n, n) :: a
DATA_TYPE, dimension(n) :: x1
DATA_TYPE, dimension(n) :: y1
DATA_TYPE, dimension(n) :: x2
DATA_TYPE, dimension(n) :: y2
integer :: n
integer :: i, j

!$pragma scop
do i = 1, _PB_N
do j = 1, _PB_N
x1(i) = x1(i) + (a(j, i) * y1(j))
end do
end do
do i = 1, _PB_N
do j = 1, _PB_N
x2(i) = x2(i) + (a(i, j) * y2(j))
end do
end do
!$pragma endscop
end subroutine
