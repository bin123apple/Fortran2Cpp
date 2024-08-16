subroutine kernel_2mm(alpha, beta, tmp, a, b, c, d,  &
ni, nj, nk, nl)
implicit none

DATA_TYPE, dimension(nj, ni) :: tmp
DATA_TYPE, dimension(nk, ni) :: a
DATA_TYPE, dimension(nj, nk) :: b
DATA_TYPE, dimension(nl, nj) :: c
DATA_TYPE, dimension(nl, ni) :: d
DATA_TYPE :: alpha, beta
integer :: ni, nj, nk, nl
integer :: i, j, k

!$pragma scop
do i = 1, _PB_NI
do j = 1, _PB_NJ
tmp(j,i) = 0.0
do k = 1, _PB_NK
tmp(j,i) = tmp(j,i) + alpha * a(k,i) * b(j,k)
end do
end do
end do

do i = 1, _PB_NI
do j = 1, _PB_NL
d(j,i) = d(j,i) * beta
do k = 1, _PB_NJ
d(j,i) = d(j,i) + tmp(k,i) * c(j,k)
end do
end do
end do
!$pragma endscop
end subroutine
