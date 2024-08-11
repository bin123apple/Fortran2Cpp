program test_clawpack46
    implicit none

    ! Declaration of variables
    integer, parameter :: maxm = 5, meqn = 2, mwaves = 3, mbc = 1, mx = 3, imp = 1
    integer :: ixy
    double precision :: ql(1-mbc:maxm+mbc, meqn)
    double precision :: qr(1-mbc:maxm+mbc, meqn)
    double precision :: aux1(1-mbc:maxm+mbc, mwaves)
    double precision :: aux2(1-mbc:maxm+mbc, mwaves)
    double precision :: aux3(1-mbc:maxm+mbc, mwaves)
    double precision :: asdq(1-mbc:maxm+mbc, meqn)
    double precision :: bmasdq(1-mbc:maxm+mbc, meqn)
    double precision :: bpasdq(1-mbc:maxm+mbc, meqn)

    ! Initialize some variables with arbitrary values for testing
    ixy = 2
    call random_number(ql)
    call random_number(qr)
    call random_number(aux1)
    call random_number(aux2)
    call random_number(aux3)
    call random_number(asdq)

    ! Calling the subroutine
    call clawpack46_rpt2adv_manifold(ixy, maxm, meqn, mwaves, mbc, mx, ql, qr, aux1, aux2, aux3, imp, asdq, bmasdq, bpasdq)

    ! Optionally: Output values or perform checks

contains

    subroutine clawpack46_rpt2adv_manifold(ixy,maxm,meqn,mwaves,mbc,mx,ql,qr,aux1,aux2,aux3,imp,asdq,bmasdq,bpasdq)
        implicit none

        integer :: ixy,maxm, meqn, mwaves, mbc, mx, imp, m
        double precision, dimension(1-mbc:maxm+mbc, meqn) :: ql, qr, asdq, bmasdq, bpasdq
        double precision, dimension(1-mbc:maxm+mbc, *) :: aux1, aux2, aux3

        integer :: iface, i, i1

        iface = 3-ixy  
        do i = 2-mbc,mx+mbc
            i1 = i-2+imp    
            do m = 1,meqn
                bmasdq(i,m) = min(aux2(i1,iface+1), 0.d0) * asdq(i,m)
                bpasdq(i,m) = max(aux3(i1,iface+1), 0.d0) * asdq(i,m)
            end do
        end do

    end subroutine clawpack46_rpt2adv_manifold

end program test_clawpack46