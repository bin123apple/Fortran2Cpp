subroutine print_array(n, a)
implicit none

DATA_TYPE, dimension(n, n) :: a
integer :: n
integer :: i,j
do i = 1, n
do j = 1, n
write(0, DATA_PRINTF_MODIFIER) a(j, i)
if (mod((i - 1) * n + j - 1, 20) == 0) then
write(0, *)
end if
end do
end do
write(0, *)
end subroutine
