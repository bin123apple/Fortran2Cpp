program test_depsto
    implicit none
    integer, parameter :: mxtime = 10
    integer :: i, idep
    real :: dtime, avedep, dinf, xmul, relast
    real, dimension(mxtime) :: recum, f, retemp, re
    ! Initialize variables for the test case
    i = 5
    idep = 0
    dtime = 1.0
    avedep = 2.0
    dinf = 0.5
    xmul = 1.0
    relast = 0.0
    recum = (/1, 2, 3, 4, 5, 6, 7, 8, 9, 10/)
    f = (/0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0/)
    retemp = (/0, 0, 0, 0, 0, 0, 0, 0, 0, 0/)
    re = (/0, 0, 0, 0, 1, 0, 0, 0, 0, 0/)

    ! Call the subroutine
    call depsto(i, recum, f, dtime, avedep, idep, dinf, retemp, re, xmul, relast)

    ! Print results for manual verification
    print *, 'idep:', idep
    print *, 'dinf:', dinf
    print *, 'xmul:', xmul
    print *, 'relast:', relast
    print *, 'retemp:', retemp
    print *, 're:', re
end program test_depsto

subroutine depsto(i, recum, f, dtime, avedep, idep, dinf, retemp, re, xmul, relast)
    integer, intent(in) :: i
    real, intent(inout) :: recum(mxtime), f(mxtime), dtime, avedep
    real, intent(inout) :: dinf, retemp(mxtime), re(mxtime), xmul, relast
    integer, intent(inout) :: idep
    real :: frate, redep
    integer, save :: ifst = 0
    real, save :: frate_saved
    frate = frate_saved

    if (idep.eq.0) then
        redep = recum(i+1) - relast + dinf
        if (redep.le.avedep) then
            if (re(i).gt.0.) then
                retemp(i+1) = retemp(i)
                re(i) = 0.
                ifst = 0
            else
                if (ifst.eq.0) then
                    xmul = xmul + (redep-dinf) / avedep
                    dinf = redep
                    frate = f(i-1)
                    ifst = 1
                endif
                dinf = dinf - frate * dtime
                if (dinf.lt.0.) dinf = 0.
                idep = 0
                retemp(i+1) = retemp(i)
                relast = recum(i+1)
            endif
        else
            xmul = xmul + (avedep-dinf) / avedep
            retemp(i+1) = retemp(i+1) - avedep * xmul
            idep = 1
            ifst = 1
        endif
    else
        if (re(i).gt.0.) then
            retemp(i+1) = retemp(i+1) - avedep * xmul
        else
            frate = f(i-1)
            dinf = avedep - frate * dtime
            if (dinf.lt.0.) dinf = 0.
            idep = 0
            retemp(i+1) = retemp(i)
            relast = recum(i+1)
        endif
    endif
    frate_saved = frate
end subroutine depsto