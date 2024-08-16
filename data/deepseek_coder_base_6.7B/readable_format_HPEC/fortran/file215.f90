subroutine kernel_floyd_warshall(n, path)
implicit none

DATA_TYPE, dimension(n,n) :: path
integer :: n
integer :: i, j, k

!$pragma scop
do k=1, _PB_N
do i=1, _PB_N
do j=1, _PB_N
if( path(j, i) .GE. path(k, i) + path(j, k) ) then
path(j, i) = path(k, i) + path(j, k)
end if
end do
end do
end do
!$pragma endscop
end subroutine
