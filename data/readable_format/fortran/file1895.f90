program test_mapc2m_latlong
    implicit none

    ! Declaration of pi and pi2 within the program
    double precision pi, pi2
    double precision tolerance

    ! Test variables
    double precision xc, yc, xp, yp, zp
    double precision expected_xp, expected_yp, expected_zp
    integer blockno

    ! Initialize pi, pi2, and tolerance
    pi = 3.141592653589793d0
    pi2 = 2.0d0 * pi
    tolerance = 1.0d-6

    ! Define a test case
    blockno = 1
    xc = 0.0d0
    yc = 0.0d0
    expected_xp = 1.0d0
    expected_yp = 0.0d0
    expected_zp = 0.0d0

    ! Call the subroutine
    call mapc2m_latlong(blockno, xc, yc, xp, yp, zp)

    ! Check the results
    if (abs(xp - expected_xp) > tolerance .or. &
        abs(yp - expected_yp) > tolerance .or. &
        abs(zp - expected_zp) > tolerance) then
        print *, 'Test Case 1 Failed'
    else
        print *, 'Test Case 1 Passed'
    end if

contains

    subroutine mapc2m_latlong(blockno, xc, yc, xp, yp, zp)
        implicit none

        ! Subroutine arguments
        integer blockno
        double precision xc, yc, xp, yp, zp
        double precision deg2rad, xc1, yc1

        ! Local variables, no need for a common block as pi and pi2 are available in the parent scope
        deg2rad = pi / 180.d0

        xc1 = deg2rad*xc
        yc1 = deg2rad*yc

        xp = cos(yc1)*cos(xc1)
        yp = cos(yc1)*sin(xc1)
        zp = sin(yc1)
    end subroutine mapc2m_latlong

end program test_mapc2m_latlong