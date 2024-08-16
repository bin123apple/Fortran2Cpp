subroutine kernel_covariance(m, n, float_n, dat, symmat, mean)
implicit none

DATA_TYPE, dimension(m, m) :: symmat
DATA_TYPE, dimension(n, m) :: dat
DATA_TYPE, dimension(m) :: mean
DATA_TYPE :: float_n
integer :: m, n
integer :: i, j, j1, j2
!$pragma scop
!       Determine mean of column vectors of input data matrix
do j = 1, _PB_M
mean(j) = 0.0D0
do i = 1, _PB_N
mean(j) = mean(j) + dat(j, i)
end do
mean(j) = mean(j) / float_n
end do

!       Center the column vectors.
do i = 1, _PB_N
do j = 1, _PB_M
dat(j, i) = dat(j, i) - mean(j)
end do
end do

!       Calculate the m * m covariance matrix.
do j1 = 1, _PB_M
do j2 = j1, _PB_M
symmat(j2, j1) = 0.0D0
do i = 1, _PB_N
symmat(j2, j1) = symmat(j2, j1) + (dat(j1, i) * dat(j2, i))
end do
symmat(j1, j2) = symmat(j2, j1)
end do
end do
!$pragma endscop
end subroutine
