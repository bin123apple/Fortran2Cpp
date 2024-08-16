subroutine print_array(ni, nl, g)
implicit none

DATA_TYPE, dimension(nl, ni) :: g
integer :: ni, nl
integer :: i, j
do i = 1, ni
do j = 1, nl
write(0, DATA_PRINTF_MODIFIER) g(j,i)
if (mod(((i - 1) * ni) + j - 1, 20) == 0) then
write(0, *)
end if
end do
end do
write(0, *)
end subroutine
