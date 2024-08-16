subroutine print_array(n, outArray)
implicit none

DATA_TYPE, dimension(n) :: outArray
integer :: n
integer :: i
do i = 1, n
write(0, DATA_PRINTF_MODIFIER) outArray(i)
if (mod(i - 1, 20) == 0) then
write(0, *)
end if
end do
end subroutine
