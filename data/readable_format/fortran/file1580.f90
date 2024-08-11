program test_radcur
    implicit none

    real :: ratio, rdlat, decl
    integer :: day, hr

    rdlat = 0.5
    decl = 0.1

    ! Test Case 1
    day = 100
    hr = 12
    call radcur(day, hr, rdlat, decl, ratio)
    print *, 'Test 1 - Day:', day, ' Hour:', hr, ' Ratio:', ratio
    
    ! Test Case 2
    day = 200
    hr = 6
    call radcur(day, hr, rdlat, decl, ratio)
    print *, 'Test 2 - Day:', day, ' Hour:', hr, ' Ratio:', ratio
    
    ! Test Case 3
    day = 300
    hr = 18
    call radcur(day, hr, rdlat, decl, ratio)
    print *, 'Test 3 - Day:', day, ' Hour:', hr, ' Ratio:', ratio

contains

    subroutine radcur(day, hr, rdlat, decl, ratio)
        real :: ratio, rdlat, decl
        integer :: day, hr
        real :: pi, slrtm, hasun, haset, harise, solcon, rdsun, dfact

        pi = 3.141593
        solcon = 0.082

        dfact = ((2 * pi) * (day - 81)) / 365

        slrtm = (0.1645 * sin(2 * dfact)) - (0.1255 * cos(dfact)) - &
                (0.025 * sin(dfact))

        hasun = ((hr + slrtm) - 12) * (pi / 12)

        haset = hasun - (pi / 24)

        harise = hasun + (pi / 24)

        rdsun = 1 + 0.033 * cos((2 * pi * day) / 365)

        ratio = ((12 * 60) / pi) * solcon * rdsun * (cos(rdlat) * &
                 cos(decl) * (sin(harise) - sin(haset)) + &
                 (harise - haset) * sin(rdlat) * sin(decl))

        if (ratio < 0.0) then
            ratio = 0.0
        endif
    end subroutine radcur

end program test_radcur