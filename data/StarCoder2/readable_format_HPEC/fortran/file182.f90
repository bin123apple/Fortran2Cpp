subroutine vecset(n, v, iv, nzv, i, val)

implicit           none

integer            n, iv(*), nzv, i, k
double precision   v(*), val


logical set

set = .false.
do k = 1, nzv
if (iv(k) .eq. i) then
v(k) = val
set  = .true.
endif
enddo
if (.not. set) then
nzv     = nzv + 1
v(nzv)  = val
iv(nzv) = i
endif
return
end
