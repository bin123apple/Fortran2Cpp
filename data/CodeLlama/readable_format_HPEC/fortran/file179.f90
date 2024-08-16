subroutine cffts2(is, d1, d2, d3, x, xout, y1, y2)


use ft_data
implicit none

integer is, d1, d2, d3, logd2
double complex x(d1+1,d2,d3)
double complex xout(d1+1,d2,d3)
double complex y1(fftblockpad, d2), y2(fftblockpad, d2)
integer i, j, k, ii, in

logd2 = ilog2(d2)

if (timers_enabled) call timer_start(T_ffty)
do k = 1, d3
do in = 0, d1/fftblock - 1
ii = in*fftblock
do j = 1, d2
do i = 1, fftblock
y1(i,j) = x(i+ii,j,k)
enddo
enddo

call cfftz (is, logd2, d2, y1, y2)

do j = 1, d2
do i = 1, fftblock
xout(i+ii,j,k) = y1(i,j)
enddo
enddo
enddo
enddo
if (timers_enabled) call timer_stop(T_ffty)

return
end
