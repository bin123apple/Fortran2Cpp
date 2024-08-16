subroutine print_array(nx, ny, s, q)
implicit none

DATA_TYPE, dimension(ny) :: s
DATA_TYPE, dimension(nx) :: q
integer :: nx,ny
integer :: i
do i = 1, ny
write(0, DATA_PRINTF_MODIFIER) s(i)
if (mod(i - 1, 80) == 0) then
write(0, *)
end if
end do

do i = 1, nx
write(0, DATA_PRINTF_MODIFIER) q(i)
if (mod(i - 1, 80) == 0) then
write(0, *)
end if
end do
write(0, *)
end subroutine
