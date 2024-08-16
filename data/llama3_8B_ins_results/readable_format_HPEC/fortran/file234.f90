subroutine init_array(alpha, beta, a, b, c ,d, ni, nj,  &
nk, nl)
implicit none

DATA_TYPE, dimension(nk, ni) :: a
DATA_TYPE, dimension(nj, nk) :: b
DATA_TYPE, dimension(nl, nj) :: c
DATA_TYPE, dimension(nl, ni) :: d
DATA_TYPE :: alpha, beta
integer :: ni, nj, nk, nl
integer :: i, j

alpha = 32412;
beta = 2123;

do i = 1, ni
do j = 1, nk
a(j,i) = DBLE((i-1) * (j-1)) / ni
end do
end do

do i = 1, nk
do j = 1, nj
b(j,i) = (DBLE((i-1) * (j)))/ nj
end do
end do

do i = 1, nl
do j = 1, nj
c(j,i) = (DBLE(i-1) * (j+2))/ nl
end do
end do

do i = 1, ni
do j = 1, nl
d(j,i) = (DBLE(i-1) * (j+1))/ nk
end do
end do
end subroutine
