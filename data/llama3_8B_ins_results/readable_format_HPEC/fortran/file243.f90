subroutine kernel_symm(ni, nj, alpha, beta, c, a, b)
implicit none

DATA_TYPE, dimension(nj, nj) :: a
DATA_TYPE, dimension(nj, ni) :: b
DATA_TYPE, dimension(nj, ni) :: c
DATA_TYPE :: alpha, beta
DATA_TYPE :: acc
integer :: ni, nj
integer :: i, j, k

!$pragma scop
do i = 1, _PB_NI
do j = 1, _PB_NJ
acc = 0.0D0
do k = 1, j - 2
c(j, k) = c(j, k) + (alpha * a(i, k) * b(j, i))
acc = acc + (b(j, k) * a(i, k))
end do
c(j, i) = (beta * c(j, i)) + (alpha * a(i, i) * b(j, i)) + &
(alpha * acc)
end do
end do
!$pragma endscop
end subroutine
