subroutine init_array(ni, nj, alpha, beta, c, a)
implicit none

DATA_TYPE, dimension(ni, ni) :: a
DATA_TYPE, dimension(nj, ni) :: c
DATA_TYPE :: alpha , beta
integer :: nj, ni
integer :: i, j

alpha = 32412
beta = 2123

do i = 1, ni
do j = 1, nj
a(j, i) = (DBLE(i - 1) * DBLE(j - 1)) / DBLE(ni)
end do
do j = 1, ni
c(j, i) = ((DBLE(i - 1) * DBLE(j - 1))) / DBLE(ni)
end do
end do
end subroutine
