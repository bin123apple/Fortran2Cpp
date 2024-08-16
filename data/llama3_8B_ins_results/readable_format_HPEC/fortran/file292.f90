subroutine kernel_trmm(ni, alpha, a, b)
implicit none

DATA_TYPE, dimension(ni, ni) :: a
DATA_TYPE, dimension(ni, ni) :: b
DATA_TYPE :: alpha
integer :: ni
integer :: i, j, k

!$pragma scop
do i = 2, _PB_NI
do j = 1, _PB_NI
do k = 1, i - 1
b(j, i) = b(j, i) + (alpha * a(k, i) * b(k, j))
end do
end do
end do
!$pragma endscop
end subroutine
