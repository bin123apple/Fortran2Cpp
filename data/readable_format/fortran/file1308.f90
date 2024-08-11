program test_appmth
    implicit none

    real :: runoff, remax, efflen, ealpha, m, effdrr, peakro

    ! Example Test Case
    runoff = 0.5
    remax = 1.0
    efflen = 100.0
    ealpha = 0.2
    m = 0.5
    effdrr = 10.0

    call appmth(runoff, remax, efflen, ealpha, m, effdrr, peakro)
    print *, "Fortran Test: Peak Runoff =", peakro

contains

    subroutine appmth(runoff,remax,efflen,ealpha,m,effdrr,peakro)

        real     runoff,efflen,ealpha,m,effdrr,remax,peakro
        real     tc

        real             te,vave,tstar,vstar,qpstar,a,b,c

        if (runoff.lt.0.00000001) then
            peakro = 0
            return
        endif
        vave  = runoff/effdrr
        te    = (efflen/(ealpha*vave**(m-1)))**(1./m)
        tstar = te/effdrr
        vstar = vave/remax

        if (tstar .ge. 1.) then
            qpstar = 1./tstar**m
        else
            if (vstar .lt. 1.) then
                a  = .6*(1.-vstar)
                b  = -1.
                c  = vstar
                tc = (-b-sqrt(b**2-4*a*c))/(2*a)

                if (tstar .gt. tc) then
                    qpstar = 1./tstar
                else
                    qpstar = 1./vstar - .6*(1.-vstar)/vstar * tstar
                end if
            else
                qpstar = 1.
            end if
        end if

        peakro = vave*qpstar

    end subroutine appmth

end program test_appmth