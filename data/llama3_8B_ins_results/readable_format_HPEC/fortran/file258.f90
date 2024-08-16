subroutine print_array(nx, ny, ex, ey, hz)
implicit none

DATA_TYPE, dimension(ny, nx) :: ex
DATA_TYPE, dimension(ny, nx) :: ey
DATA_TYPE, dimension(ny, nx) :: hz
integer :: nx, ny
integer :: i, j
do i = 1, nx
do j = 1, ny
write(0, DATA_PRINTF_MODIFIER) ex(j, i)
write(0, DATA_PRINTF_MODIFIER) ey(j, i)
write(0, DATA_PRINTF_MODIFIER) hz(j, i)
if (mod(((i - 1) * nx) + j - 1, 20) == 0) then
write(0, *)
end if
end do
end do
write(0, *)
end subroutine
