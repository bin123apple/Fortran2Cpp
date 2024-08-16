subroutine init_array(maxgrid, sumTang, mean, path)
implicit none

integer :: maxgrid
DATA_TYPE, dimension (maxgrid, maxgrid) :: sumTang, mean, path
integer :: i, j
do i = 1, maxgrid
do j = 1, maxgrid
sumTang(j, i) = i * j
mean(j, i) = ( i - j ) / (maxgrid)
path(j, i) = (( i - 1 ) * ( j - 2 )) / (maxgrid)
end do
end do
end subroutine
