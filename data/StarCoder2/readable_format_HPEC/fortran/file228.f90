subroutine print_array(maxgrid, path)
implicit none

integer :: i, j, maxgrid
DATA_TYPE, dimension (maxgrid, maxgrid) :: path
do i = 1, maxgrid
do j = 1, maxgrid
write(0, DATA_PRINTF_MODIFIER) path(j, i)
if (mod(((i - 1) * maxgrid) + j - 1, 20) == 0) then
write(0, *)
end if
end do
end do
write(0, *)
end subroutine
