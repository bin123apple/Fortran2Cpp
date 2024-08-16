subroutine kernel_syr2k(ni, nj, alpha, beta, c, a, b)
implicit none

DATA_TYPE, dimension(nj, ni) :: a
DATA_TYPE, dimension(nj, ni) :: b
DATA_TYPE, dimension(ni, ni) :: c
DATA_TYPE :: alpha, beta
integer :: ni, nj
integer :: i, j, k

!$pragma scop
do i = 1, _PB_NI
do j = 1, _PB_NI
c(j, i) = c(j, i) * beta
end do
end do
do i = 1, _PB_NI
do j = 1, _PB_NI
do k = 1, _PB_NI
c(j, i) = c(j, i) + (alpha * a(k, i) * b(k, j))
c(j, i) = c(j, i) + (alpha * b(k, i) * a(k, j))
end do
end do
end do
!$pragma endscop
end subroutine
