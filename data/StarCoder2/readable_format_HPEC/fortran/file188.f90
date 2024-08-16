subroutine kernel_durbin(n, y, sumArray, alpha, beta, r,  &
outArray)
implicit none
DATA_TYPE, dimension(n, n) :: y
DATA_TYPE, dimension(n, n) :: sumArray
DATA_TYPE, dimension(n) :: beta
DATA_TYPE, dimension(n) :: alpha
DATA_TYPE, dimension(n) :: r
DATA_TYPE, dimension(n) :: outArray
integer :: i, k, n

!$pragma scop
y(1, 1) = r(1)
beta(1) = 1
alpha(1) = r(1)
do k = 2, _PB_N
beta(k) = beta(k - 1) - (alpha(k - 1) * alpha(k - 1) * &
beta(k -1))
sumArray(k, 1) = r(k)
do i = 1, k - 1
sumArray(k, i + 1) = sumArray(k, i) + &
(r(k - i) * y(k - 1, i))
end do
alpha(k) = alpha(k) - (sumArray(k, k) * beta(k))
do i = 1, k - 1
y(k, i) = y(k - 1, i) + (alpha(k) * y(k - 1, k - i))
end do
y(k, k) = alpha(k)
end do

do i = 1, _PB_N
outArray(i) = y(_PB_N, i)
end do
!$pragma endscop
end subroutine
