subroutine kernel_fdtd_apml(cz, cxm, cym, mui, ch, &
ax, ry, clf, tmp, bza, ex, ey, &
hz, czm, czp, cxmh, cxph, cymh, cyph)
implicit none
integer :: cz, cym, cxm
DATA_TYPE, dimension(cxm + 1, cym + 1, cz + 1) :: ex
DATA_TYPE, dimension(cxm + 1, cym + 1, cz + 1) :: ey
DATA_TYPE, dimension(cxm + 1, cym + 1, cz + 1) :: hz
DATA_TYPE, dimension(cym + 1, cz + 1) :: clf
DATA_TYPE, dimension(cym + 1, cz + 1) :: ry
DATA_TYPE, dimension(cym + 1, cz + 1) :: ax
DATA_TYPE, dimension(cym + 1) :: cymh
DATA_TYPE, dimension(cym + 1) :: cyph
DATA_TYPE, dimension(cxm + 1) :: cxmh
DATA_TYPE, dimension(cxm + 1) :: cxph
DATA_TYPE, dimension(cz + 1) :: czm
DATA_TYPE, dimension(cz + 1) :: czp
DATA_TYPE, dimension(cxm + 1, cym + 1) :: tmp
DATA_TYPE, dimension(cxm + 1, cym + 1, cz + 1) :: bza
DATA_TYPE :: mui, ch
integer :: ix, iy, iz

!$pragma scop
do iz = 1, _PB_CZ
do iy = 1, _PB_CYM
do ix = 1, _PB_CXM
clf(iy, iz) = ex(ix, iy, iz) - ex(ix, iy + 1, iz) + &
ey(ix + 1, iy, iz) - ey(ix, iy, iz)
tmp(iy, iz) = ((cymh(iy) / cyph(iy)) * bza(ix, iy, iz)) - &
((ch / cyph(iy)) * clf(iy, iz))
hz(ix, iy, iz) = ((cxmh(ix) / cxph(ix)) * hz(ix, iy, iz)) &
+ ((mui * czp(iz) / cxph(ix)) * tmp(iy, iz)) &
- ((mui * czm(iz) / cxph(ix)) * &
bza(ix, iy, iz))
bza(ix, iy, iz) = tmp(iy, iz)
end do
clf(iy, iz) = ex(_PB_CXM + 1, iy, iz) - &
ex(_PB_CXM + 1, iy + 1, iz) + &
ry(iy, iz) - ey(_PB_CXM + 1, iy, iz)
tmp(iy, iz) = ((cymh(iy) / cyph(iy)) * &
bza(_PB_CXM + 1, iy, iz)) - ((ch / cyph(iy))  &
* clf(iy, iz))
hz(_PB_CXM + 1, iy, iz) = ((cxmh(_PB_CXM + 1) / &
cxph(_PB_CXM + 1)) * &
hz(_PB_CXM + 1, iy, iz)) + &
((mui * czp(iz) / &
cxph(_PB_CXM + 1)) * &
tmp(iy, iz)) - &
((mui * czm(iz) / &
cxph(_PB_CXM + 1)) * &
bza(_PB_CXM + 1, iy, iz))
bza(_PB_CXM + 1, iy, iz) = tmp(iy, iz)

do ix = 1, _PB_CXM
clf(iy, iz) = ex(ix, _PB_CYM + 1, iz) - ax(ix, iz) + &
ey(ix + 1, _PB_CYM + 1, iz) - &
ey(ix, _PB_CYM + 1, iz)
tmp(iy, iz) = ((cymh(_PB_CYM + 1) / cyph(iy)) * &
bza(ix, iy, iz)) - ((ch / cyph(iy)) * &
clf(iy, iz))
hz(ix, _PB_CYM + 1, iz) = ((cxmh(ix) / cxph(ix)) * &
hz(ix, _PB_CYM + 1, iz)) + &
((mui * czp(iz) / cxph(ix)) * &
tmp(iy, iz)) - &
((mui * czm(iz) / cxph(ix)) * &
bza(ix, _PB_CYM + 1, iz))
bza(ix, _PB_CYM + 1, iz) = tmp(iy, iz)
end do
clf(iy, iz) = ex(_PB_CXM + 1, _PB_CYM + 1, iz) - &
ax(_PB_CXM + 1, iz) + ry(_PB_CYM + 1, iz) - &
ey(_PB_CXM + 1, _PB_CYM + 1, iz)
tmp(iy, iz) = ((cymh(_PB_CYM + 1) / cyph(_PB_CYM + 1)) * &
bza(_PB_CXM + 1, _PB_CYM + 1, iz)) - &
((ch / cyph(_PB_CYM + 1)) * clf(iy, iz))
hz(_PB_CXM + 1, _PB_CYM + 1, iz) = &
((cxmh(_PB_CXM + 1) / cxph(_PB_CXM + 1)) * &
hz(_PB_CXM + 1, _PB_CYM + 1, iz)) + &
((mui * czp(iz) / cxph(_PB_CXM + 1)) * tmp(iy, iz)) - &
((mui * czm(iz) / cxph(_PB_CXM + 1)) * &
bza(_PB_CXM + 1, _PB_CYM + 1, iz))
bza(_PB_CXM + 1, _PB_CYM + 1, iz) = tmp(iy, iz)
end do
end do

!$pragma endscop
end subroutine
