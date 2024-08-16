subroutine init_array(ni, nj, nk, alpha, beta, c, a, b)
implicit none

DATA_TYPE, dimension(nk, ni) :: a
DATA_TYPE, dimension(nj, nk) :: b
DATA_TYPE, dimension(nj, ni) :: c
DATA_TYPE :: alpha, beta
integer :: ni, nj, nk
integer :: i, j

alpha = 32412
beta = 2123

do i = 1, ni
do j = 1, nj
c(j, i) = ((DBLE(i - 1) * DBLE(j - 1))) / DBLE(ni)
end do
end do
do i = 1, ni
do j = 1, nk
a(j, i) = ((DBLE(i - 1) * DBLE(j - 1))) / DBLE(ni)
end do
end do
do i = 1, nk
do j = 1, nj
b(j, i) = ((DBLE(i - 1) * DBLE(j - 1))) / DBLE(ni)
end do
end do
end subroutine
