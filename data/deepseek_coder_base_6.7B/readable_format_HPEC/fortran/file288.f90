subroutine print_array(cz, cxm, cym, bza, ex, ey, hz)
implicit none

integer :: cz, cxm, cym
DATA_TYPE, dimension(cxm + 1, cym + 1, cz + 1) :: bza
DATA_TYPE, dimension(cxm + 1, cym + 1, cz + 1) :: ex
DATA_TYPE, dimension(cxm + 1, cym + 1, cz + 1) :: ey
DATA_TYPE, dimension(cxm + 1, cym + 1, cz + 1) :: hz
integer :: i, j, k

do i = 1, cz + 1
do j = 1, cym + 1
do k = 1, cxm + 1
write(0, DATA_PRINTF_MODIFIER) bza(k, j, i)
write(0, DATA_PRINTF_MODIFIER) ex(k, j, i)
write(0, DATA_PRINTF_MODIFIER) ey(k, j, i)
write(0, DATA_PRINTF_MODIFIER) hz(k, j, i)
if (mod(((i - 1) * cxm) + j - 1, 20) == 0) then
write(0, *)
end if
end do
end do
end do
write(0, *)
end subroutine
