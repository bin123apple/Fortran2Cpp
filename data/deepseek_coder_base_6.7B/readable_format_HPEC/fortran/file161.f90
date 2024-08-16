subroutine cffts3(is, d1, d2, d3, x, xout, y1, y2)


use ft_data
implicit none

integer is, d1, d2, d3, logd3
double complex x(d1+1,d2,d3)
double complex xout(d1+1,d2,d3)
double complex y1(fftblockpad, d3), y2(fftblockpad, d3)
integer i, j, k, ii, in

logd3 = ilog2(d3)

if (timers_enabled) call timer_start(T_fftz)
do j = 1, d2
do in = 0, d1/fftblock - 1
ii = in*fftblock
do k = 1, d3
do i = 1, fftblock
y1(i,k) = x(i+ii,j,k)
enddo
enddo

call cfftz (is, logd3, d3, y1, y2)

do k = 1, d3
do i = 1, fftblock
xout(i+ii,j,k) = y1(i,k)
enddo
enddo
enddo
enddo
if (timers_enabled) call timer_stop(T_fftz)

return
end
