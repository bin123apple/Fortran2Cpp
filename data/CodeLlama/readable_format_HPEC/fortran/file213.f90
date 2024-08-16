subroutine print_array(n, w)
implicit none

DATA_TYPE, dimension(n) :: w
integer :: n
integer :: i, j
do i = 1, n
write(0, DATA_PRINTF_MODIFIER) w(i)
if (mod(i - 1, 20) == 0) then
write(0, *)
end if
end do
write(0, *)
end subroutine
