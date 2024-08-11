! Define the subroutine
subroutine fclaw2d_clawpatch5_fort_timeinterp(mx,my,mbc,meqn,psize, qcurr,qlast,qinterp,alpha,ierror)
  implicit none

  integer mx,my,mbc,meqn,psize, ierror
  double precision alpha
  double precision   qcurr(meqn,1-mbc:mx+mbc,1-mbc:my+mbc)
  double precision   qlast(meqn,1-mbc:mx+mbc,1-mbc:my+mbc)
  double precision qinterp(meqn,1-mbc:mx+mbc,1-mbc:my+mbc)

  integer i,j, m,mint,k,kfinal, ng

  mint = 2
  ierror = 0
  k = 1

  ng = 0

  do m = 1,meqn
     do j = 1-ng,my-mint
        do i = 1-ng,mint
           qinterp(m,i,j) = qlast(m,i,j) + alpha*(qcurr(m,i,j)-qlast(m,i,j))
           k = k + 1
        enddo
     enddo

     do j = 1-ng,mint
        do i = mint+1,mx+ng
           qinterp(m,i,j) = qlast(m,i,j) + alpha*(qcurr(m,i,j)-qlast(m,i,j))
           k = k + 1
        enddo
     enddo

     do j = mint+1,my+ng
        do i = mx-mint+1,mx+ng
           qinterp(m,i,j) = qlast(m,i,j) + alpha*(qcurr(m,i,j)-qlast(m,i,j))
           k = k + 1
        enddo
     enddo

     do j = my-mint+1,my+ng
        do i = 1-ng,mx-mint
           qinterp(m,i,j) = qlast(m,i,j) + alpha*(qcurr(m,i,j)-qlast(m,i,j))
           k = k + 1
        enddo
     enddo

  enddo

  kfinal = k-1;
  if (kfinal .ne. psize) then
     ierror = 2
  endif

end subroutine fclaw2d_clawpatch5_fort_timeinterp

! Test program
program test_clawpatch
  implicit none
  integer, parameter :: mx=10, my=10, mbc=2, meqn=1, psize=100
  double precision, allocatable :: qcurr(:,:,:), qlast(:,:,:), qinterp(:,:,:)
  double precision :: alpha = 0.5
  integer :: ierror

  allocate(qcurr(meqn, 1-mbc:mx+mbc, 1-mbc:my+mbc))
  allocate(qlast(meqn, 1-mbc:mx+mbc, 1-mbc:my+mbc))
  allocate(qinterp(meqn, 1-mbc:mx+mbc, 1-mbc:my+mbc))

  ! Initialize qcurr and qlast with some test values
  qcurr = 1.0
  qlast = 0.5

  call fclaw2d_clawpatch5_fort_timeinterp(mx, my, mbc, meqn, psize, qcurr, qlast, qinterp, alpha, ierror)

  ! Write qinterp to standard output or check its values
  print *, qinterp

  deallocate(qcurr, qlast, qinterp)
end program test_clawpatch