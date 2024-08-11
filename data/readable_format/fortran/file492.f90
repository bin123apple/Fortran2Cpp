program test_fft99a
    implicit none
    double precision, allocatable :: a(:), work(:), trigs(:)
    integer :: n, inc, jump, lot
    integer :: i
    double precision :: pi

    ! Define pi
    pi = acos(-1.0d0)

    ! Initialize test parameters
    n = 4
    inc = 1
    jump = 1
    lot = 1
    allocate(a(n*2), work(n*2), trigs(n*2))
    
    ! Initialize test data
    a = (/0.0d0, 1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0, 6.0d0, 7.0d0/)
    work = 0.0d0
    trigs = (/cos(0.0d0), sin(0.0d0), cos(pi/4.0d0), sin(pi/4.0d0), &
              cos(pi/2.0d0), sin(pi/2.0d0), cos(3.0*pi/4.0d0), sin(3.0*pi/4.0d0)/)

    ! Call the subroutine
    call fft99a(a, work, trigs, inc, jump, n, lot)

    ! Print results for verification
    print *, 'work ='
    do i = 1, n*2
        print *, work(i)
    end do

contains

    subroutine fft99a(a,work,trigs,inc,jump,n,lot)
        double precision, dimension(*) :: a,work,trigs
        integer :: n,inc,jump,lot
        integer :: nh,nx,ink,ia,ib,ja,jb,iabase,ibbase,jabase,jbbase,k,l
        double precision :: c,s

        nh=n/2
        nx=n+1
        ink=inc+inc
        ia=1
        ib=n*inc+1
        ja=1
        jb=2
        do 10 l=1,lot
            work(ja)=a(ia)+a(ib)
            work(jb)=a(ia)-a(ib)
            ia=ia+jump
            ib=ib+jump
            ja=ja+nx
            jb=jb+nx
10      continue
        iabase=2*inc+1
        ibbase=(n-2)*inc+1
        jabase=3
        jbbase=n-1
        do 30 k=3,nh,2
            ia=iabase
            ib=ibbase
            ja=jabase
            jb=jbbase
            c=trigs(n+k)
            s=trigs(n+k+1)
            do 20 l=1,lot
                work(ja)=(a(ia)+a(ib))-(s*(a(ia)-a(ib))+c*(a(ia+inc)+a(ib+inc)))
                work(jb)=(a(ia)+a(ib))+(s*(a(ia)-a(ib))+c*(a(ia+inc)+a(ib+inc)))
                work(ja+1)=(c*(a(ia)-a(ib))-s*(a(ia+inc)+a(ib+inc)))+(a(ia+inc)-a(ib+inc))
                work(jb+1)=(c*(a(ia)-a(ib))-s*(a(ia+inc)+a(ib+inc)))-(a(ia+inc)-a(ib+inc))
                ia=ia+jump
                ib=ib+jump
                ja=ja+nx
                jb=jb+nx
20          continue
            iabase=iabase+ink
            ibbase=ibbase-ink
            jabase=jabase+2
            jbbase=jbbase-2
30      continue
        if (iabase.eq.ibbase) then
            ia=iabase
            ja=jabase
            do 40 l=1,lot
                work(ja)=2.0*a(ia)
                work(ja+1)=-2.0*a(ia+inc)
                ia=ia+jump
                ja=ja+nx
40          continue
        endif
    end subroutine fft99a

end program test_fft99a