subroutine print_array(n, a)
implicit none

DATA_TYPE, dimension(n) :: a
integer :: n
integer :: i

do i = 1, n
write(0, DATA_PRINTF_MODIFIER) a(i)
if (mod(i - 1, 20) == 0) then
write(0, *)
end if
end do
write(0, *)
end subroutine
