subroutine print_array(d, ni, nl)
implicit none

DATA_TYPE, dimension(nl, ni) :: d
integer :: nl, ni
integer :: i, j
do i = 1, ni
do j = 1, nl
write(0, DATA_PRINTF_MODIFIER) d(j,i)

if (mod(((i - 1) * ni) + j - 1, 20) == 0) then
write(0, *)
end if

end do
end do
write(0, *)
end subroutine
