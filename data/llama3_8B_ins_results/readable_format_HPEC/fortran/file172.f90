subroutine ssor(niter)



use lu_data
implicit none

integer niter

integer i, j, k, m, n
integer istep
double precision  tmp, tmp2
double precision  delunm(5)

external timer_read
double precision timer_read


tmp = 1.0d+00 / ( omega * ( 2.0d+00 - omega ) )

do i = 1, t_last
call timer_clear(i)
end do

call rhs

call l2norm( isiz1, isiz2, isiz3, nx0, ny0, nz0,  &
&             ist, iend, jst, jend,  &
&             rsd, rsdnm )


do i = 1, t_last
call timer_clear(i)
end do
call timer_start(1)

do istep = 1, niter

if (mod ( istep, 20) .eq. 0 .or.  &
&         istep .eq. itmax .or.  &
&         istep .eq. 1) then
if (niter .gt. 1) write( *, 200) istep
200        format(' Time step ', i4)
endif

if (timeron) call timer_start(t_rhs)
tmp2 = dt
do k = 2, nz - 1
do j = jst, jend
do i = ist, iend
do m = 1, 5
rsd(m,i,j,k) = tmp2 * rsd(m,i,j,k)
end do
end do
end do
end do
if (timeron) call timer_stop(t_rhs)

if (timeron) call timer_start(t_blts)
do k = 2, nz -1
do j = jst, jend

call jacld(j, k)

call blts( isiz1, isiz2, isiz3,  &
&                    nx, ny, nz,  &
&                    omega,  &
&                    rsd,  &
&                    a, b, c, d,  &
&                    ist, iend, j, k )

end do
end do
if (timeron) call timer_stop(t_blts)

if (timeron) call timer_start(t_buts)
do k = nz - 1, 2, -1
do j = jend, jst, -1

call jacu(j, k)

call buts( isiz1, isiz2, isiz3,  &
&                    nx, ny, nz,  &
&                    omega,  &
&                    rsd,  &
&                    d, a, b, c,  &
&                    ist, iend, j, k )

end do
end do
if (timeron) call timer_stop(t_buts)


if (timeron) call timer_start(t_add)
tmp2 = tmp
do k = 2, nz-1
do j = jst, jend
do i = ist, iend
do m = 1, 5
u( m, i, j, k ) = u( m, i, j, k )  &
&                    + tmp2 * rsd( m, i, j, k )
end do
end do
end do
end do
if (timeron) call timer_stop(t_add)

if ( mod ( istep, inorm ) .eq. 0 ) then
if (timeron) call timer_start(t_l2norm)
call l2norm( isiz1, isiz2, isiz3, nx0, ny0, nz0,  &
&                   ist, iend, jst, jend,  &
&                   rsd, delunm )
if (timeron) call timer_stop(t_l2norm)
end if

call rhs

if ( ( mod ( istep, inorm ) .eq. 0 ) .or.  &
&        ( istep .eq. itmax ) ) then
if (timeron) call timer_start(t_l2norm)
call l2norm( isiz1, isiz2, isiz3, nx0, ny0, nz0,  &
&                   ist, iend, jst, jend,  &
&                   rsd, rsdnm )
if (timeron) call timer_stop(t_l2norm)
end if

if ( ( rsdnm(1) .lt. tolrsd(1) ) .and.  &
&        ( rsdnm(2) .lt. tolrsd(2) ) .and.  &
&        ( rsdnm(3) .lt. tolrsd(3) ) .and.  &
&        ( rsdnm(4) .lt. tolrsd(4) ) .and.  &
&        ( rsdnm(5) .lt. tolrsd(5) ) ) then
write (*,1004) istep
go to 900
end if

end do
900 continue

call timer_stop(1)
maxtime= timer_read(1)



return

1001 format (1x/5x,'pseudo-time SSOR iteration no.=',i4/)
1004 format (1x/1x,'convergence was achieved after ',i4,  &
&   ' pseudo-time steps' )
1006 format (1x/1x,'RMS-norm of SSOR-iteration correction ',  &
& 'for first pde  = ',1pe12.5/,  &
& 1x,'RMS-norm of SSOR-iteration correction ',  &
& 'for second pde = ',1pe12.5/,  &
& 1x,'RMS-norm of SSOR-iteration correction ',  &
& 'for third pde  = ',1pe12.5/,  &
& 1x,'RMS-norm of SSOR-iteration correction ',  &
& 'for fourth pde = ',1pe12.5/,  &
& 1x,'RMS-norm of SSOR-iteration correction ',  &
& 'for fifth pde  = ',1pe12.5)
1007 format (1x/1x,'RMS-norm of steady-state residual for ',  &
& 'first pde  = ',1pe12.5/,  &
& 1x,'RMS-norm of steady-state residual for ',  &
& 'second pde = ',1pe12.5/,  &
& 1x,'RMS-norm of steady-state residual for ',  &
& 'third pde  = ',1pe12.5/,  &
& 1x,'RMS-norm of steady-state residual for ',  &
& 'fourth pde = ',1pe12.5/,  &
& 1x,'RMS-norm of steady-state residual for ',  &
& 'fifth pde  = ',1pe12.5)

end
