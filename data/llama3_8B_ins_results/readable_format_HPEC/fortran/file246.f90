subroutine print_array(y, ny)
implicit none

DATA_TYPE, dimension(ny) :: y
integer :: ny
integer :: i
do i = 1, ny
write(0, DATA_PRINTF_MODIFIER) y(i)
if (mod(i - 1, 20) == 0) then
write(0, *)
end if
end do
write(0, *)
end subroutine
