subroutine sparse( a, colidx, rowstr, n, nz, nonzer, arow, acol,  &
&                   aelt, firstrow, lastrow,  &
&                   v, iv, nzloc, rcond, shift )

use tinfo

implicit           none

integer            colidx(*), iv(*)
integer            firstrow, lastrow
integer            n, nonzer, arow(*), acol(nonzer+1,*)
integer(kz)        nz, rowstr(*)
double precision   a(*), aelt(nonzer+1,*), v(*), rcond, shift

integer            nzloc(n), nrows


integer            i, j, jcol
integer(kz)        j1, j2, nza, k, kk, nzrow
double precision   xi, size, scale, ratio, va

nrows = lastrow - firstrow + 1
j1 = ilow + 1
j2 = ihigh + 1

do j = j1, j2
rowstr(j) = 0
enddo

do i = 1, n
do nza = 1, arow(i)
j = acol(nza, i)
if (j.ge.ilow .and. j.le.ihigh) then
j = j + 1
rowstr(j) = rowstr(j) + arow(i)
endif
end do
end do

if (myid .eq. 0) then
rowstr(1) = 1
j1 = 1
endif
do j = j1+1, j2
rowstr(j) = rowstr(j) + rowstr(j-1)
enddo
if (myid .lt. num_threads) last_n(myid) = rowstr(j2)

nzrow = 0
if (myid .lt. num_threads) then
do i = 0, myid-1
nzrow = nzrow + last_n(i)
end do
endif
if (nzrow .gt. 0) then
do j = j1, j2
rowstr(j) = rowstr(j) + nzrow
enddo
endif
nza = rowstr(nrows+1) - 1


if (nza .gt. nz) then
write(*,*) 'Space for matrix elements exceeded in sparse'
write(*,*) 'nza, nzmax = ',nza, nz
stop
endif


do j = ilow, ihigh
do k = rowstr(j), rowstr(j+1)-1
v(k) = 0.d0
iv(k) = 0
enddo
nzloc(j) = 0
enddo


size = 1.0D0
ratio = rcond ** (1.0D0 / dfloat(n))

do i = 1, n
do nza = 1, arow(i)
j = acol(nza, i)

if (j .lt. ilow .or. j .gt. ihigh) goto 60

scale = size * aelt(nza, i)
do nzrow = 1, arow(i)
jcol = acol(nzrow, i)
va = aelt(nzrow, i) * scale

if (jcol .eq. j .and. j .eq. i) then
va = va + rcond - shift
endif

do k = rowstr(j), rowstr(j+1)-1
if (iv(k) .gt. jcol) then
do kk = rowstr(j+1)-2, k, -1
if (iv(kk) .gt. 0) then
v(kk+1)  = v(kk)
iv(kk+1) = iv(kk)
endif
enddo
iv(k) = jcol
v(k)  = 0.d0
goto 40
else if (iv(k) .eq. 0) then
iv(k) = jcol
goto 40
else if (iv(k) .eq. jcol) then
nzloc(j) = nzloc(j) + 1
goto 40
endif
enddo
print *,'internal error in sparse: i=',i
stop
40          continue
v(k) = v(k) + va
enddo
60       continue
enddo
size = size * ratio
enddo


do j = ilow+1, ihigh
nzloc(j) = nzloc(j) + nzloc(j-1)
enddo
if (myid .lt. num_threads) last_n(myid) = nzloc(ihigh)

nzrow = 0
if (myid .lt. num_threads) then
do i = 0, myid-1
nzrow = nzrow + last_n(i)
end do
endif
if (nzrow .gt. 0) then
do j = ilow, ihigh
nzloc(j) = nzloc(j) + nzrow
enddo
endif

do j = 1, nrows
if (j .gt. 1) then
j1 = rowstr(j) - nzloc(j-1)
else
j1 = 1
endif
j2 = rowstr(j+1) - nzloc(j) - 1
nza = rowstr(j)
do k = j1, j2
a(k) = v(nza)
colidx(k) = iv(nza)
nza = nza + 1
enddo
enddo
do j = 2, nrows+1
rowstr(j) = rowstr(j) - nzloc(j-1)
enddo
nza = rowstr(nrows+1) - 1


return
11000   format ( //,'final nonzero count in sparse ',  &
&            /,'number of nonzeros       = ', i16 )
end
