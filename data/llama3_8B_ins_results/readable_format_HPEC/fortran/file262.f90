subroutine print_array(ni, c)
implicit none

DATA_TYPE, dimension(ni, ni) :: c
integer :: ni
integer :: i, j
do i = 1, ni
do j = 1, ni
write(0, DATA_PRINTF_MODIFIER) c(j, i)
if (mod(((i - 1) * ni) + j - 1, 20) == 0) then
write(0, *)
end if
end do
end do
write(0, *)
end subroutine
