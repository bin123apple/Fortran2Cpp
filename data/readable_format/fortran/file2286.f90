program test_jac
    implicit none
    integer, parameter :: Neq = 10
    integer, parameter :: nrowpd = 10
    real*8 :: t
    real*8 :: Y(Neq)
    real*8 :: pd(nrowpd, Neq)
    integer :: mlow, mup
    integer :: i, j
    real*8 :: gr

    common /block1/ gr

    ! Initialize variables
    t = 0.0
    mlow = 0
    mup = 0
    gr = 9.81d0

    ! Initialize Y array
    do i = 1, Neq
        Y(i) = 0.0d0
    end do

    ! Call the subroutine
    call jac(Neq, t, Y, mlow, mup, pd, nrowpd)

    ! Print the pd matrix for verification
    do i = 1, nrowpd
        do j = 1, Neq
            write(*, '(F8.4)', advance='no') pd(i, j)
        end do
        write(*, *)
    end do

end program test_jac

subroutine jac (Neq,t,Y,mlow,mup,pd,nrowpd)
    implicit none
    integer*4 Neq,nb,i,j,mlow,mup,nrowpd
    real*8 t,Y(Neq),pd(nrowpd,Neq)
    integer*4 nt,ntmax,N0
    real*8 gr,xtmm,xtmp

    common /block1/ gr

    ntmax=Neq/2   
    N0=ntmax-1

    do i=1,nrowpd
        do j=1,Neq
            pd(i,j)=0.d0
        end do
    end do

    do nt=1,ntmax
        xtmm=(nt-1)*(nt-1)
        pd(5,2*(nt-1)+2)=pd(5,2*(nt-1)+2)+0.5*gr*xtmm
        pd(7,2*(nt-1)+1)=pd(7,2*(nt-1)+1)-0.5*gr*xtmm
    end do

    do nt=1,ntmax
        xtmm=(N0-nt+1)*(N0-nt+1)
        pd(5,2*(nt-1)+2)=pd(5,2*(nt-1)+2)+0.5*gr*xtmm
        pd(7,2*(nt-1)+1)=pd(7,2*(nt-1)+1)-0.5*gr*xtmm
    end do

    do nt=1,ntmax
        xtmm=-(nt-1)*(N0-nt+1)*2
        pd(5,2*(nt-1)+2)=pd(5,2*(nt-1)+2)+0.5*gr*xtmm
        pd(7,2*(nt-1)+1)=pd(7,2*(nt-1)+1)-0.5*gr*xtmm
    end do

    return
end