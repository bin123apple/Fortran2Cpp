subroutine init_array(n, path)
implicit none

DATA_TYPE, dimension(n,n) :: path
integer :: i, j, n

do i=1, n
do j=1, n
path(j, i) = (DBLE(i * j))/ DBLE(n)
end do
end do
end subroutine
