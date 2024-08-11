program test_writecvg
    implicit none
    integer, parameter :: ne = 2
    double precision :: ram(ne) = [0.1d0, 0.2d0]
    double precision :: qam(ne) = [0.1d0, 0.2d0]
    double precision :: cam(ne) = [0.1d0, 0.2d0]
    double precision :: uam(ne) = [0.1d0, 0.2d0]
    integer :: ithermal

    call writecvg(1, 1, 0, 0, ne, 1, ram, qam, cam, uam, 0)
    call writecvg(1, 1, 0, 0, ne, 1, ram, qam, cam, uam, 1)
    call writecvg(1, 1, 0, 0, ne, 1, ram, qam, cam, uam, 2)

contains

    subroutine writecvg(istep, iinc, icutb, iit, ne, ne0, ram, qam, cam, uam, ithermal)
        implicit none
        integer istep, iinc, icutb, iit, ne, ne0, ithermal
        double precision, dimension(*) :: ram, qam, cam, uam
        double precision :: residforce, corrdisp, residflux, corrtemp

        ! Place the original subroutine logic here
        print *, 'This is a test output for ithermal = ', ithermal
        ! The actual calculation and printing logic is omitted for brevity
    end subroutine writecvg

end program test_writecvg