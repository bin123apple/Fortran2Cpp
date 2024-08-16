subroutine print_array(a, nr, nq, np)
implicit none

DATA_TYPE, dimension(np, nq, nr) :: a
integer :: nr, nq, np
integer :: i, j, k
do i = 1, nr
do j = 1, nq
do k = 1, np
write(0, DATA_PRINTF_MODIFIER) a(k, j, i)
if (mod((i - 1), 20) &
== 0) then
write(0, *)
end if
end do
end do
end do
write(0, *)
end subroutine
