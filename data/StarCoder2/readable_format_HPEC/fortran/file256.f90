subroutine init_array(cz, cxm, cym, mui, ch, ax, ry, ex, ey, hz, &
czm, czp, cxmh, cxph, cymh, cyph)
implicit none

integer :: cz, cym, cxm
DATA_TYPE, dimension(cxm + 1, cym + 1, cz + 1) :: ex
DATA_TYPE, dimension(cxm + 1, cym + 1, cz + 1) :: ey
DATA_TYPE, dimension(cxm + 1, cym + 1, cz + 1) :: hz
DATA_TYPE, dimension(cym + 1, cz + 1) :: ry
DATA_TYPE, dimension(cym + 1, cz + 1) :: ax
DATA_TYPE, dimension(cym + 1) :: cymh
DATA_TYPE, dimension(cym + 1) :: cyph
DATA_TYPE, dimension(cxm + 1) :: cxmh
DATA_TYPE, dimension(cxm + 1) :: cxph
DATA_TYPE, dimension(cz + 1) :: czm
DATA_TYPE, dimension(cz + 1) :: czp
DATA_TYPE :: mui, ch
integer :: i, j, k

mui = 2341
ch = 42
do i = 1, cz + 1
czm(i) = (DBLE(i - 1) + 1.0D0) / DBLE(cxm)
czp(i) = (DBLE(i - 1) + 2.0D0) / DBLE(cxm)
end do
do i = 1, cxm + 1
cxmh(i) = (DBLE(i - 1) + 3.0D0) / DBLE(cxm)
cxph(i) = (DBLE(i - 1) + 4.0D0) / DBLE(cxm)
end do
do i = 1, cym + 1
cymh(i) = (DBLE(i - 1) + 5.0D0) / DBLE(cxm)
cyph(i) = (DBLE(i - 1) + 6.0D0) / DBLE(cxm)
end do
do i = 1, cz + 1
do j = 1, cym + 1
ry(j, i) = ((DBLE(i - 1) * DBLE(j)) + 10.0D0) / &
DBLE(cym)
ax(j, i) = ((DBLE(i - 1) * DBLE(j + 1)) + 11.0D0) / &
DBLE(cym)
do k = 1, cxm + 1
ex(k, j, i) = ((DBLE(i - 1) * DBLE(j + 2)) + DBLE(k - 1) + &
1.0D0) / DBLE(cxm)
ey(k, j, i) = ((DBLE(i - 1) * DBLE(j + 3)) + DBLE(k - 1) + &
2.0D0) / DBLE(cym)
hz(k, j, i) = ((DBLE(i - 1) * DBLE(j + 4)) + DBLE(k - 1) + &
3.0D0) / DBLE(cz)
end do
end do
end do
end subroutine
