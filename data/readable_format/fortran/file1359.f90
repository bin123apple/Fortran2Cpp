program test_decodems
  implicit none
  complex, dimension(224) :: cdat
  complex, dimension(56,0:63) :: cw
  real, dimension(0:63,400) :: s2
  character(len=400) :: msg
  integer :: i, j, npts, nchar, i1

  ! Initialize test data
  npts = 224
  nchar = 4
  i1 = 1
  do i = 1, npts
    cdat(i) = cmplx(real(i), real(i))  ! Corrected line
  enddo
  do i = 1, 56
    do j = 0, 63
      cw(i,j) = cmplx(real(i+j), real(i-j))  ! Corrected line
    enddo
  enddo

  ! Initialize s2 to zeros (optional, for clarity)
  s2 = 0.0

  ! Call the subroutine
  call decodems(cdat, npts, cw, i1, nchar, s2, msg)

  ! Output the result
  print *, "Message:", trim(msg)
end program test_decodems

subroutine decodems(cdat,npts,cw,i1,nchar,s2,msg)
  complex cdat(npts)
  complex cw(56,0:63)
  real s2(0:63,400)
  character(len=400) :: msg
  complex z
  character(len=64) :: cc
  integer :: i, j, k, kk, ia, kpk
  real :: smax, ss

  data cc/'0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ./?-                 _     @'/

  msg=' '
  kpk=0
  do j=1,nchar
     ia=i1 + (j-1)*56
     smax=0.
     do k=0,40
        kk=k
        if(k.eq.40) kk=57
        z=cmplx(0.,0.)
        do i=1,56
           z=z + cdat(ia+i)*conjg(cw(i,kk))
        enddo
        ss=abs(z)
        s2(k,j)=ss
        if(ss.gt.smax) then
           smax=ss
           kpk=kk
        endif
     enddo
     msg(j:j)=cc(kpk+1:kpk+1)
     if(kpk.eq.57) msg(j:j)=' '
  enddo
end subroutine decodems