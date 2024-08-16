subroutine print_array(n, x1, x2)
implicit none

DATA_TYPE, dimension(n) :: x1
DATA_TYPE, dimension(n) :: x2
integer :: n
integer :: i
do i = 1, n
write(0, DATA_PRINTF_MODIFIER) x1(i)
write(0, DATA_PRINTF_MODIFIER) x2(i)
if (mod((i - 1), 20) == 0) then
write(0, *)
end if
end do
write(0, *)
end subroutine
