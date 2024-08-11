subroutine dqpsrt(limit, last, maxerr, ermax, elist, iord, nrmax)
    integer, intent(in) :: limit, last
    integer, intent(inout) :: maxerr, iord(last), nrmax
    real*8, intent(inout) :: ermax, elist(last)
    integer :: i, ibeg, ido, isucc, j, jbnd, jupbn, k
    real*8 :: errmax, errmin

    if (last <= 2) then
        iord(1) = 1
        iord(2) = 2
        return
    endif

    errmax = elist(maxerr)
    if (nrmax /= 1) then
        ido = nrmax - 1
        do i = 1, ido
            isucc = iord(nrmax - 1)
            if (errmax <= elist(isucc)) exit
            iord(nrmax) = isucc
            nrmax = nrmax - 1
        end do
    endif

    jupbn = last
    if (last > (limit / 2 + 2)) jupbn = limit + 3 - last
    errmin = elist(last)
    jbnd = jupbn - 1
    ibeg = nrmax + 1
    if (ibeg <= jbnd) then
        do i = ibeg, jbnd
            isucc = iord(i)
            if (errmax >= elist(isucc)) exit
            iord(i - 1) = isucc
        end do
        goto 50
    endif

    iord(jbnd) = maxerr
    iord(jupbn) = last
    goto 90

50  continue
    iord(i - 1) = maxerr
    k = jbnd
    do j = i, jbnd
        isucc = iord(k)
        if (errmin < elist(isucc)) exit
        iord(k + 1) = isucc
        k = k - 1
    end do
    iord(i) = last
    goto 90

    iord(k + 1) = last

90  continue
    maxerr = iord(nrmax)
    ermax = elist(maxerr)
end subroutine dqpsrt

program testDqpsrt
    implicit none
    integer, parameter :: last = 5
    integer :: limit, maxerr, nrmax, i
    real*8 :: ermax
    real*8 :: elist(last)
    integer :: iord(last)

    ! Initialize variables
    limit = 10
    maxerr = 2
    nrmax = 1
    ermax = 0.0
    elist = (/0.1, 0.2, 0.05, 0.3, 0.25/)
    iord = (/1, 2, 3, 4, 5/)

    ! Call the subroutine
    call dqpsrt(limit, last, maxerr, ermax, elist, iord, nrmax)

    ! Output results for verification
    print *, "maxerr:", maxerr
    print *, "ermax:", ermax
    print *, "nrmax:", nrmax
    print *, "iord:", iord
end program testDqpsrt