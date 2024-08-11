program testMove
  implicit none

  real*4 p1(131072), p2(131072), wl1(131072), wl2(131072)
  real*8 disp1(9), disp2(9)
  character*80 xf1, xf2
  character*20 fn1, fn2, ob1, ob2
  character*4 type1, type2
  character*3 xa1, xa2
  integer np1, np2
  integer i

  ! Initialize some test data
  np1 = 100
  xa1 = 'abc'
  ob1 = 'Object1'
  fn1 = 'Filename1'
  xf1 = 'ExtendedFilename1'
  type1 = 'typ1'
  do i=1,131072
     p1(i) = real(i)
     wl1(i) = real(i) / 2.0
  enddo
  do i=1,9
     disp1(i) = real(i) * 100.0
  enddo

  ! Call the subroutine
  call move(p1,p2,wl1,wl2,disp1,disp2,np1,np2,ob1,ob2,fn1,fn2,xf1,xf2,xa1,xa2,type1,type2)

  ! Check results - Here we just print a confirmation for simplicity
  if (np2 == np1 .and. xa2 == xa1 .and. ob2 == ob1 .and. fn2 == fn1 .and. xf2 == xf1 .and. type2 == type1) then
    print *, "PASS: move subroutine works correctly!"
  else
    print *, "FAIL: move subroutine does not work correctly!"
  endif

end program testMove

subroutine move (p1,p2,wl1,wl2,disp1,disp2,np1,np2,ob1,ob2,fn1,fn2,xf1,xf2,xa1,xa2,type1,type2)

  real*4 p1(131072), p2(131072), wl1(131072), wl2(131072)
  real*8 disp1(9), disp2(9)
  character*80 xf1, xf2
  character*20 fn1, fn2, ob1, ob2
  character*4 type1, type2
  character*3 xa1, xa2
  integer np1, np2
  integer i

  xa2 = xa1
  np2 = np1
  ob2 = ob1
  fn2 = fn1
  xf2 = xf1
  type2 = type1

  do i=1,131072
     p2(i) = p1(i)
     wl2(i) = wl1(i)
  enddo

  do i=1,9
     disp2(i) = disp1(i)
  enddo

end subroutine move