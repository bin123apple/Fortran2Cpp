program test_writeevcs
    implicit none

    integer, parameter :: nx = 6
    real(kind=8) :: x(nx)
    integer :: nm
    real(kind=8) :: xmin, xmax

    ! Initialize test data
    nm = 1
    xmin = -0.5
    xmax = 1.5
    x = [0.25d0, -0.5d0, 0.75d0, 1.0d0, -1.25d0, 1.5d0]

    call writeevcs(x, nx, nm, xmin, xmax)

contains

    subroutine writeevcs(x, nx, nm, xmin, xmax)
        implicit none

        integer, intent(in) :: nx, nm
        real(kind=8), intent(in) :: x(nx), xmin, xmax
        real(kind=8) :: pi, xnull
        integer :: j

        pi = 4.d0*atan(1.d0)
        xnull = 0.d0

        print *, ''
        print *, '    E I G E N V A L U E   O U T P U T'
        print *, ''
        print *, ' NODAL   MODE NO    EIGENVALUE                      FREQUENCY'
        print *, 'DIAMETER                                    REAL PART           IMAGINARY PART'
        print *, '                                   (RAD/TIME)      (CYCLES/TIME)   (RAD/TIME)'
        print *, ''

        do j = 1, nx
            if (xmin > -0.5d0) then
                if (xmin*xmin > x(j)) cycle
            endif

            if (xmax > -0.5d0) then
                if (xmax*xmax < x(j)) exit
            endif

            if (x(j) < 0.d0) then
                print '(i5,4x,i7,4(2x,e14.7))', nm, j, x(j), xnull, &
                xnull, dsqrt(-x(j))
            else
                print '(i5,4x,i7,4(2x,e14.7))', nm, j, x(j), dsqrt(x(j)), &
                dsqrt(x(j)) / (2.d0*pi), xnull
            endif
        end do
    end subroutine writeevcs

end program test_writeevcs