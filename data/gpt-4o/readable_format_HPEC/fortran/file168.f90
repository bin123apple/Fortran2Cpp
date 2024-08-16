subroutine cfftz (is, m, n, x, y)



use ft_data
implicit none

integer is,m,n,i,j,l,mx
double complex x, y

dimension x(fftblockpad,n), y(fftblockpad,n)

mx = u(1)
if ((is .ne. 1 .and. is .ne. -1) .or. m .lt. 1 .or. m .gt. mx)    &
&  then
write (*, 1)  is, m, mx
1      format ('CFFTZ: Either U has not been initialized, or else'/    &
&    'one of the input parameters is invalid', 3I5)
stop
endif

do l = 1, m, 2
call fftz2 (is, l, m, n, fftblock, fftblockpad, u, x, y)
if (l .eq. m) goto 160
call fftz2 (is, l + 1, m, n, fftblock, fftblockpad, u, y, x)
enddo

goto 180

160  do j = 1, n
do i = 1, fftblock
x(i,j) = y(i,j)
enddo
enddo

180  continue

return
end
