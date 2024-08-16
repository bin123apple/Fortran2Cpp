subroutine kernel_3mm(ni, nj, nk, nl, nm, e, a, b, f, c, d, g)
implicit none

DATA_TYPE, dimension(nk, ni) :: a
DATA_TYPE, dimension(nj, nk) :: b
DATA_TYPE, dimension(nm, nj) :: c
DATA_TYPE, dimension(nl, nm) :: d
DATA_TYPE, dimension(nj, ni) :: e
DATA_TYPE, dimension(nl, nj) :: f
DATA_TYPE, dimension(nl, ni) :: g
integer :: ni, nj, nk, nl, nm
integer :: i, j, k

!$pragma scop
! E := A*B
do i = 1, _PB_NI
do j = 1, _PB_NJ
e(j,i) = 0.0
do k = 1, _PB_NK
e(j,i) = e(j,i) + a(k,i) * b(j,k)
end do
end do
end do

! F := C*D
do i = 1, _PB_NJ
do j = 1, _PB_NL
f(j,i) = 0.0
do k = 1, _PB_NM
f(j,i) = f(j,i) + c(k,i) * d(j,k)
end do
end do
end do

! G := E*F
do i = 1, _PB_NI
do j = 1, _PB_NL
g(j,i) = 0.0
do k = 1, _PB_NJ
g(j,i) = g(j,i) + e(k,i) * f(j,k)
end do
end do
end do
!$pragma endscop

end subroutine
