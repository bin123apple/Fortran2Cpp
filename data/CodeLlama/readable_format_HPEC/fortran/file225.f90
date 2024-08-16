subroutine kernel_lu(n, a)
implicit none

DATA_TYPE, dimension(n, n) :: a
integer :: n
integer :: i, j, k

!$pragma scop
do k = 1, _PB_N
do j = k + 1, _PB_N
a(j, k) = a(j, k) / a(k, k)
end do
do i = k + 1, _PB_N
do j = k + 1, _PB_N
a(j, i) = a(j, i) - (a(k, i) * a(j, k))
end do
end do
end do
!$pragma endscop
end subroutine
