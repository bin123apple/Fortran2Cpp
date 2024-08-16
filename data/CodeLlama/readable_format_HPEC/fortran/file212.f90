subroutine kernel_gramschmidt(ni, nj, a, r, q)
implicit none

DATA_TYPE, dimension(nj, ni) :: a
DATA_TYPE, dimension(nj, nj) :: r
DATA_TYPE, dimension(nj, ni) :: q
DATA_TYPE :: nrm
integer :: ni, nj
integer :: i, j, k

!$pragma scop
do k = 1, _PB_NJ
nrm = 0.0D0
do i = 1, _PB_NI
nrm = nrm + (a(k, i) * a(k, i))
end do
r(k, k) = sqrt(nrm)
do i = 1, _PB_NI
q(k, i) = a(k, i) / r(k, k)
end do
do j = k + 1, _PB_NJ
r(j, k) = 0.0D0
do i = 1, _PB_NI
r(j, k) = r(j, k) + (q(k, i) * a(j, i))
end do
do i = 1, _PB_NI
a(j, i) = a(j, i) - (q(k, i) * r(j, k))
end do
end do
end do
!$pragma endscop
end subroutine
