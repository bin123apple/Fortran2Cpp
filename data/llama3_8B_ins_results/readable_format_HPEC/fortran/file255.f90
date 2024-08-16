subroutine print_array(ni, nj, a, r, q)
implicit none

DATA_TYPE, dimension(nj, ni) :: a
DATA_TYPE, dimension(nj, nj) :: r
DATA_TYPE, dimension(nj, ni) :: q
integer :: ni, nj
integer :: i, j
do i = 1, ni
do j = 1, nj
write(0, DATA_PRINTF_MODIFIER) a(j, i)
if (mod((i - 1), 20) == 0) then
write(0, *)
end if
end do
end do
write(0, *)
do i = 1, nj
do j = 1, nj
write(0, DATA_PRINTF_MODIFIER) r(j, i)
if (mod((i - 1), 20) == 0) then
write(0, *)
end if
end do
end do
write(0, *)
do i = 1, ni
do j = 1, nj
write(0, DATA_PRINTF_MODIFIER) q(j, i)
if (mod((i - 1), 20) == 0) then
write(0, *)
end if
end do
end do
write(0, *)
end subroutine
