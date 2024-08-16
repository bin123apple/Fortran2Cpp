subroutine makea( n, nz, a, colidx, rowstr,  &
&                  firstrow, lastrow, firstcol, lastcol,  &
&                  arow, acol, aelt, v, iv )

use tinfo
use cg_data, only : nonzer, rcond, shift

implicit none

integer             n
integer(kz)         nz, rowstr(n+1)
integer             firstrow, lastrow, firstcol, lastcol
integer             colidx(nz)
integer             iv(n+nz), arow(n), acol(nonzer+1,n)
double precision    aelt(nonzer+1,n), v(nz)
double precision    a(nz)


integer          i, iouter, ivelt, nzv, nn1
integer          ivc(nonzer+1)
double precision vc(nonzer+1)


external          sparse, sprnvc, vecset
integer           work



nn1 = 1
50   continue
nn1 = 2 * nn1
if (nn1 .lt. n) goto 50

num_threads = 1
myid = 0
if (num_threads .gt. max_threads) then
if (myid .eq. 0) write(*,100) num_threads, max_threads
100      format(' Warning: num_threads',i6,  &
&          ' exceeded an internal limit',i6)
num_threads = max_threads
endif
work  = (n + num_threads - 1)/num_threads
ilow  = work * myid + 1
ihigh = ilow + work - 1
if (ihigh .gt. n) ihigh = n

do iouter = 1, ihigh
nzv = nonzer
call sprnvc( n, nzv, nn1, vc, ivc )
if ( iouter .ge. ilow ) then
call vecset( n, vc, ivc, nzv, iouter, .5D0 )
arow(iouter) = nzv
do ivelt = 1, nzv
acol(ivelt, iouter) = ivc(ivelt)
aelt(ivelt, iouter) = vc(ivelt)
enddo
endif
enddo

call sparse( a, colidx, rowstr, n, nz, nonzer, arow, acol,  &
&             aelt, firstrow, lastrow,  &
&             v, iv(1), iv(nz+1), rcond, shift )
return

end
