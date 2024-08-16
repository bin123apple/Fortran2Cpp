subroutine kernel_correlation(m, n, float_n, dat, symmat, &
mean, stddev)
implicit none

DATA_TYPE, dimension(n,m) :: dat
DATA_TYPE, dimension(m,m) :: symmat
DATA_TYPE, dimension(m) :: stddev
DATA_TYPE, dimension(m) :: mean
DATA_TYPE :: float_n, EPS
integer :: m, n
integer :: i, j, j1, j2

EPS = 0.1D0
!$pragma scop
!       Determine mean of column vectors of input data matrix
do j = 1, _PB_M
mean(j) = 0.0D0
do i = 1, _PB_N
mean(j) = mean(j) + dat(j, i)
end do
mean(j) = mean(j) / float_n
end do

!       Determine standard deviations of column vectors of data matrix.
do j = 1, _PB_M
stddev(j) = 0.0D0
do i = 1, _PB_N
stddev(j) = stddev(j) + (dat(j, i) - mean(j)) * (dat(j, i) - &
mean(j))
end do
stddev(j) = stddev(j) / float_n
stddev(j) = sqrt(stddev(j))
if (stddev(j) <= EPS) then
stddev(j) = 1.0D0
endif
end do

!       Center and reduce the column vectors.
do i = 1, _PB_N
do j = 1, _PB_M
dat(j, i) = dat(j, i) - mean(j)
dat(j, i) = dat(j, i) / (sqrt(float_n) * stddev(j))
end do
end do

!       Calculate the m * m correlation matrix.
do j1 = 1, _PB_M - 1
symmat(j1, j1) = 1.0D0
do j2 = j1 + 1, _PB_M
symmat(j2, j1) = 0.0D0
do i = 1, _PB_N
symmat(j2, j1) = symmat(j2, j1) + (dat(j1, i) * dat(j2, i))
end do
symmat(j1, j2) = symmat(j2, j1)
end do
end do
symmat(_PB_M, _PB_M) = 1.0D0
!$pragma endscop
end subroutine
