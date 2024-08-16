subroutine cffts1(is, d1, d2, d3, x, xout, y1, y2)


use ft_data
implicit none

integer is, d1, d2, d3, logd1
double complex x(d1+1,d2,d3)
double complex xout(d1+1,d2,d3)
double complex y1(fftblockpad, d1), y2(fftblockpad, d1)
integer i, j, k, jj, jn

logd1 = ilog2(d1)

if (timers_enabled) call timer_start(T_fftx)
do k = 1, d3
do jn = 0, d2/fftblock - 1
jj = jn*fftblock
do j = 1, fftblock
do i = 1, d1
y1(j,i) = x(i,j+jj,k)
enddo
enddo

call cfftz (is, logd1, d1, y1, y2)


do j = 1, fftblock
do i = 1, d1
xout(i,j+jj,k) = y1(j,i)
enddo
enddo
enddo
enddo
if (timers_enabled) call timer_stop(T_fftx)

return
end
