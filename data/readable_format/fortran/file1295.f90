program test_radresult
  implicit none
  
  integer, parameter :: ntr = 3
  double precision :: xloadact(2,ntr), tarea(ntr), tenv(ntr)
  double precision :: physcon(2), erad(ntr), auview(2*ntr), fenv(ntr)
  double precision :: bcr(ntr), q(ntr)
  integer :: nloadtr(ntr), irowrad(2*ntr), jqrad(ntr+1), nzsrad
  integer :: i

  ! Initialize variables with some test values
  nzsrad = ntr
  do i=1, ntr
     bcr(i) = i
     nloadtr(i) = i
     tarea(i) = 1.0
     tenv(i) = 300.0
     auview(i) = 0.1*i
     auview(nzsrad+i) = 0.2*i
     erad(i) = 5.67E-8
     fenv(i) = 0.5
     irowrad(i) = i
     jqrad(i) = i
     physcon(1) = 273.15
     physcon(2) = 5.67E-8
  end do
  jqrad(ntr+1) = ntr+1

  call radresult(ntr,xloadact,bcr,nloadtr,tarea,tenv,physcon,erad,auview,fenv,irowrad,jqrad,nzsrad,q)

  ! Print results for verification
  do i=1, ntr
     print *, 'q(', i, ') = ', q(i)
     print *, 'xloadact(2,', i, ') = ', xloadact(2,i)
  end do

contains

  subroutine radresult(ntr,xloadact,bcr,nloadtr,tarea,tenv,physcon,erad,auview,fenv,irowrad,jqrad,nzsrad,q)
    implicit none

    integer i,j,k,ntr,nloadtr(*),irowrad(*),jqrad(*),nzsrad
    real*8 xloadact(2,*), tarea(*),tenv(*),auview(*),erad(*),fenv(*),physcon(*),bcr(ntr),q(*)

    do i=1,ntr
       q(i)=bcr(i)
    end do

    do i=1,ntr
       do j=jqrad(i),jqrad(i+1)-1
          k=irowrad(j)
          q(k)=q(k)-auview(j)*bcr(i)

          q(i)=q(i)-auview(nzsrad+j)*bcr(k)
       end do
    end do

    do i=1,ntr
       j=nloadtr(i)
       q(i)=q(i)-fenv(i)*physcon(2)*tenv(i)**4
       xloadact(2,j)= max(tarea(i)**4-q(i)/(erad(i)*physcon(2)),0.d0)
       xloadact(2,j)=(xloadact(2,j))**0.25d0+physcon(1)
    end do
  end subroutine radresult

end program test_radresult