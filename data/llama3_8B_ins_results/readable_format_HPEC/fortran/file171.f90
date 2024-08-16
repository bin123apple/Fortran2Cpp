subroutine sprnvc( n, nz, nn1, v, iv )

use cg_data, only : amult, tran

implicit           none

double precision   v(*)
integer            n, nz, nn1, iv(*)



integer            nzv, ii, i, icnvrt

external           randlc, icnvrt
double precision   randlc, vecelt, vecloc


nzv = 0

100     continue
if (nzv .ge. nz) goto 110

vecelt = randlc( tran, amult )

vecloc = randlc(tran, amult)
i = icnvrt(vecloc, nn1) + 1
if (i .gt. n) goto 100

do ii = 1, nzv
if (iv(ii) .eq. i) goto 100
enddo
nzv = nzv + 1
v(nzv) = vecelt
iv(nzv) = i
goto 100
110     continue

return
end
