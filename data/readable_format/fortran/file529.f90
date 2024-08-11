program test_rect_norm
    implicit none
    integer, parameter :: ntpol = 3
    real :: xscal, yscal, zscal
    integer :: lstpx(ntpol), lstpy(ntpol), lstpz(ntpol)
    real :: bnorm(ntpol)
    integer :: i

    ! Define test inputs
    xscal = 1.0
    yscal = 2.0
    zscal = 3.0
    lstpx = (/1, 2, 3/)
    lstpy = (/2, 3, 4/)
    lstpz = (/3, 4, 5/)

    ! Call the subroutine
    call rect_norm(ntpol, xscal, yscal, zscal, lstpx, lstpy, lstpz, bnorm)

    ! Output the results
    print *, 'Test case 1 results:'
    do i = 1, ntpol
        print *, 'bnorm(', i, ')=', bnorm(i)
    end do

contains

    subroutine rect_norm(ntpol,xscal,yscal,zscal,lstpx,lstpy,lstpz,bnorm)
        implicit none
        integer ntpol,lstpx(*),lstpy(*),lstpz(*)
        real  bnorm(*),xscal,yscal,zscal
        real  ilxyz
        integer n

        ilxyz=xscal*yscal*zscal*0.125      
        do n=1,ntpol
            bnorm(n)=sqrt((2.0*lstpx(n)+1.0)*(2.0*lstpy(n)+1.0)*(2.0*lstpz(n)+1.0)*ilxyz)
        enddo
    end subroutine rect_norm

end program test_rect_norm