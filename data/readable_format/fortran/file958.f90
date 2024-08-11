program test_qinit
    implicit none
    double precision, allocatable :: q(:,:)
    double precision, allocatable :: aux(:,:)
    integer :: mx, meqn, mbc, maxmx, maux
    double precision :: xlower, dx
    integer :: i

    ! Test parameters
    maxmx = 100
    meqn = 2
    mbc = 1
    mx = 5
    xlower = 0.0
    dx = 0.01
    maux = 0

    ! Allocate arrays
    allocate(q(1-mbc:maxmx+mbc,meqn))
    allocate(aux(1-mbc:maxmx+mbc,maux))

    ! Call the subroutine
    call qinit(maxmx,meqn,mbc,mx,xlower,dx,q,maux,aux)

    ! Check and print first few values of q for testing
    do i=1,5
        print *, 'q(', i, ',1) = ', q(i,1)
        print *, 'q(', i, ',2) = ', q(i,2)
    end do

    ! Deallocate arrays
    deallocate(q)
    deallocate(aux)
end program test_qinit

subroutine qinit(maxmx,meqn,mbc,mx,xlower,dx,q,maux,aux)
    implicit double precision (a-h,o-z)
    dimension q(1-mbc:maxmx+mbc, meqn)
    dimension aux(1-mbc:maxmx+mbc, *)
    common /cqinit/ beta
    integer i
    double precision xcell

    do 150 i=1,mx
        xcell = xlower + (i-0.5d0)*dx
        q(i,1) = 0.5d0*dexp(-80.d0*xcell**2)
        if (dabs(xcell+0.2d0) .lt. 0.1d0) then
            q(i,1) = q(i,1) + 0.5d0
        endif
        q(i,2) = 0.d0
150 continue
    return
end