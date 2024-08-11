program test_dcdt
    implicit none
    real, allocatable :: y(:)
    integer :: npts, indx1, indx2
    real :: dt
    logical :: ldc, ldt

    ! Initialize test variables
    npts = 5
    allocate(y(npts))
    y = (/1.0, 2.0, 3.0, 4.0, 5.0/)
    dt = 1.0
    indx1 = 1
    indx2 = 5
    ldc = .true.
    ldt = .false.

    ! Call the subroutine with ldc = true
    call dcdt(y, dt, npts, indx1, indx2, ldc, ldt)
    print *, 'Results with ldc = true:', y

    ! Reset y for the next test
    y = (/1.0, 2.0, 3.0, 4.0, 5.0/)
    ldc = .false.
    ldt = .true.

    ! Call the subroutine with ldt = true
    call dcdt(y, dt, npts, indx1, indx2, ldc, ldt)
    print *, 'Results with ldt = true:', y

contains

    subroutine dcdt (y,dt,npts,indx1,indx2,ldc,ldt)
        real, intent(inout) :: y(*)
        real, intent(in) :: dt
        integer, intent(in) :: npts, indx1, indx2
        logical, intent(in) :: ldc, ldt
        integer :: i, nsum
        real :: xsubi, sumxy, sumx, sumx2, sumy, avy, bxy, axy, qxy

        if (.not. ldc .and. .not. ldt) then
            return
        end if

        nsum = indx2-indx1+1
        sumx = 0.0
        sumx2 = 0.0
        sumy = 0.0
        sumxy = 0.0
        do i=indx1,indx2
            xsubi = (i-1)*dt
            sumxy = sumxy+xsubi*y(i)
            sumx = sumx+xsubi
            sumx2 = sumx2+xsubi*xsubi
            sumy = sumy+y(i)
        end do

        if (ldc) then
            avy = sumy/nsum
            do i=1,npts
                y(i) = y(i)-avy
            end do
            write(*,'(a)') ' indx1, indx2, avy'
            write(*,*) indx1, indx2, avy
            return
        endif

        if (ldt) then
            bxy = (sumxy-sumx*sumy/nsum)/(sumx2-sumx*sumx/nsum)
            axy = (sumy-bxy*sumx)/nsum
            qxy = dt*bxy
            do i=1,npts
                y(i) = y(i)-(axy+(i-1)*qxy)
            end do
            return
        endif

        return
    end subroutine dcdt

end program test_dcdt