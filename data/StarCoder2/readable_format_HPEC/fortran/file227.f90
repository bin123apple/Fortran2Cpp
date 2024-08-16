subroutine kernel_gemm(ni, nj, nk, alpha, beta, c, a, b)
implicit none

DATA_TYPE, dimension(nk, ni) :: a
DATA_TYPE, dimension(nj, nk) :: b
DATA_TYPE, dimension(nj, ni) :: c
DATA_TYPE :: alpha, beta
integer :: ni, nj, nk
integer :: i, j, k

!$pragma scop
do i = 1, _PB_NI
do j = 1, _PB_NJ
c(j, i) = c(j, i) * beta
do k  = 1, _PB_NK
c(j, i) = c(j, i) + (alpha * a(k, i) * b(j, k))
end do
end do
end do
!$pragma endscop
end subroutine
