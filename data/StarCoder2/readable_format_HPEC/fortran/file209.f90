subroutine init_array(ni, nj, alpha, beta, c, a, b)
implicit none

DATA_TYPE, dimension(nj, nj) :: a
DATA_TYPE, dimension(nj, ni) :: b
DATA_TYPE, dimension(nj, ni) :: c
DATA_TYPE :: alpha, beta
integer :: ni, nj
integer :: i, j

alpha = 32412D0
beta = 2123D0

do i = 1, ni
do j = 1, nj
c(j, i) = ((DBLE((i - 1) * (j - 1)))) / DBLE(ni)
b(j, i) = ((DBLE((i - 1) * (j - 1)))) / DBLE(ni)
end do
end do
do i = 1, nj
do j = 1, nj
a(j, i) = (DBLE((i - 1) * (j - 1))) / DBLE(ni)
end do
end do
end subroutine
