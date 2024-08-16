subroutine init_array(n, y, sumArray, alpha, beta, r)
implicit none

DATA_TYPE, dimension(n, n) :: y
DATA_TYPE, dimension(n, n) :: sumArray
DATA_TYPE, dimension(n) :: beta
DATA_TYPE, dimension(n) :: alpha
DATA_TYPE, dimension(n) :: r
integer :: i, j
integer :: n

do i = 1, n
alpha(i) = i
beta(i) = (i/n)/DBLE(2.0)
r(i)  = (i/n)/DBLE(4.0)
do j = 1, n
y(j,i) = DBLE(i*j)/DBLE(n)
sumArray(j,i) = DBLE(i*j)/DBLE(n)
end do
end do
end subroutine
