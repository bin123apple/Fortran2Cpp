subroutine init_array(ni, nj, nk, nl, nm, a, b, c , d)
implicit none

DATA_TYPE, dimension(nk, ni) :: a
DATA_TYPE, dimension(nj, nk) :: b
DATA_TYPE, dimension(nm, nj) :: c
DATA_TYPE, dimension(nl, nm) :: d
integer :: ni, nj, nk, nl, nm
integer :: i, j

do i = 1, ni
do j = 1, nk
a(j,i) = DBLE(i-1) * DBLE(j-1) / ni
end do
end do

do i = 1, nk
do j = 1, nj
b(j,i) = (DBLE(i-1) * DBLE(j))/ nj
end do
end do

do i = 1, nj
do j = 1, nm
c(j,i) = (DBLE(i-1) * DBLE(j+2))/ nl
end do
end do

do i = 1, nm
do j = 1, nl
d(j,i) = (DBLE(i-1) * DBLE(j+1))/ nk
end do
end do
end subroutine
