! calc_time.f90
subroutine calc_time(ds, dsmin, dt, dtmin, tss, tseas, ts, tt, dxyz, dstep, iter, rb, dsc)
    implicit none
    integer,        intent(in) :: iter
    real(kind=8),   intent(in) :: dsmin, dtmin, tseas, dxyz, dstep
    real(kind=8),   intent(inout) :: ds, tss, tt, ts
    real(kind=8),   intent(out) :: dt, rb, dsc
    real(kind=8) :: rbg

    if (ds == dsmin) then
        dt = dtmin
    else
        dt = ds * dxyz
    endif

    if (dt < 0.d0) then
        print *, 'dt=', dt
        stop 49673
    endif

    if (tss + dt / tseas * dble(iter) >= dble(iter)) then
        dt = (floor(ts) + 1.d0) * tseas - tt
        tt = (floor(ts) + 1.d0) * tseas
        ts = floor(ts) + 1.d0
        tss = dble(iter)
        ds = dt / dxyz
    else
        tt = tt + dt
        if (dt == dtmin) then
            ts = ts + dstep
            tss = tss + 1.d0
        else
            ts = ts + dt / tseas
            tss = tss + dt / tseas * dble(iter)
        endif
    endif

    dsc = ds
    rbg = ts
    rb = 1.d0 - rbg
end subroutine

program test
    implicit none
    real(kind=8) :: ds, dsmin, dt, dtmin, tss, tseas, ts, tt, dxyz, dstep, rb, dsc
    integer :: iter

    ! Initialize variables
    ds = 1.0d0
    dsmin = 0.1d0
    dtmin = 0.01d0
    tss = 0.0d0
    tseas = 1.0d0
    ts = 0.0d0
    tt = 0.0d0
    dxyz = 0.1d0
    dstep = 0.1d0
    iter = 10

    ! Call subroutine
    call calc_time(ds, dsmin, dt, dtmin, tss, tseas, ts, tt, dxyz, dstep, iter, rb, dsc)

    ! Display results
    print *, 'ds =', ds
    print *, 'dt =', dt
    print *, 'tss =', tss
    print *, 'ts =', ts
    print *, 'tt =', tt
    print *, 'rb =', rb
    print *, 'dsc =', dsc
end program test