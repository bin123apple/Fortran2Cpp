subroutine init_array(n, a)
implicit none

DATA_TYPE, dimension(n, n) :: a
integer :: n
integer :: i,j
do i = 1, n
do j = 1, n
a(j, i) = ((DBLE(i - 1) * DBLE(j + 1)) + 2.0D0) / n
end do
end do
end subroutine
