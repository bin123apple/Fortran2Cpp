subroutine init_array(ni, nj, a, r, q)
implicit none

DATA_TYPE, dimension(nj, ni) :: a
DATA_TYPE, dimension(nj, nj) :: r
DATA_TYPE, dimension(nj, ni) :: q
integer :: ni, nj
integer :: i, j

do i = 1, ni
do j = 1, nj
a(j, i) = (DBLE(i - 1) * DBLE(j - 1)) / DBLE(ni)
q(j, i) = (DBLE(i - 1) * DBLE(j)) / DBLE(nj)
end do
end do

do i = 1, ni
do j = 1, nj
r(j, i) = (DBLE(i - 1) * DBLE(j + 1)) / DBLE(nj)
end do
end do
end subroutine
