program test_adjust
  implicit none
  integer, parameter :: km = 5, nl = 5
  real, dimension(km) :: Th, T, P
  real, dimension(km+1) :: PH
  real :: Cpd, Ps, kap
  integer :: i

  ! Initialize test data
  Cpd = 1000.0
  Ps = 100000.0
  kap = 0.286
  T = (/288.0, 290.0, 295.0, 300.0, 305.0/)
  Th = (/288.0, 290.0, 295.0, 300.0, 305.0/)
  P = (/100000.0, 95000.0, 90000.0, 85000.0, 80000.0/)
  PH = (/100500.0, 95500.0, 90500.0, 85500.0, 80500.0, 75000.0/)

  ! Call the subroutine
  call adjust(km, nl, Cpd, Ps, PH, P, T, Th, kap)

  ! Print results for manual verification
  print *, 'Adjusted T:'
  do i = 1, km
     print *, T(i)
  end do

  print *, 'Adjusted Th:'
  do i = 1, km
     print *, Th(i)
  end do

contains

  subroutine adjust(km, nl, Cpd, Ps, PH, P, T, Th, kap)
    implicit none
    integer km,nl,jn,i,j,k,jc
    real Th(km),T(km),PH(km+1),P(km),TOLD(km)
    real sum,thbar,ahm,a2,RDCP,kap,X,Cpd,Ps
    
    do k=1,km
       told(k)=0.
    enddo

    rdcp = kap

    jc=0
    do 30 i=nl-1,1,-1
       jn=0
       sum=th(i)
       do j=i+1,nl
          sum=sum+th(j)
          thbar=sum/float(j+1-i)
          if(th(j).lt.thbar)jn=j
       enddo
       if (jn.eq.0) goto 30
12    continue
       ahm=0.0
       do 15 j=i,jn
          ahm= ahm + cpd * t(j)*( ph(j)-ph(j+1) )
15    continue
       a2=0.0
       do 20 j=i,jn
          x=(p(j)/ps)**rdcp
          told(j)=t(j)
          t(j)=x
          a2=a2+cpd*x*(ph(j)-ph(j+1))
20    continue
       do 25 j=i,jn
          th(j)=ahm/a2
          t(j)=t(j)*th(j)
25    continue
       if(th(jn+1).lt.th(jn).and.jn.le.nl)then
          jn=jn+1
          goto 12
       end if
       if(i.eq.1)jc=jn 
30    continue

  end subroutine adjust

end program test_adjust