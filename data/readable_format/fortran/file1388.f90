program test_tt_calc
    implicit none
    double precision :: xflow, Tt, pt, kappa, r, A, Ts
    integer :: icase

    ! Test case setup
    xflow = 1.0d0
    pt = 1.0d0
    kappa = 1.4d0
    r = 287.0d0
    A = 1.0d0
    Ts = 288.0d0
    icase = 0

    ! Calling the subroutine
    call tt_calc(xflow, Tt, pt, kappa, r, A, Ts, icase)

    ! Output the result for verification
    print *, 'Test 1 - Tt=', Tt

contains

    subroutine tt_calc(xflow, Tt, pt, kappa, r, A, Ts, icase)
        implicit none
        integer :: icase, i
        double precision :: xflow, Tt, pt, kappa, r, A, Ts
        double precision :: f, df, expon, Tt_old, C, TtzTs, deltaTt, TtzTs_crit, Qred, h1, h2, h3
        logical :: condition

        expon = -0.5d0 * (kappa + 1.d0) / (kappa - 1.d0)
        C = sqrt(2.d0 / r * kappa / (kappa - 1.d0))
        
        if (abs(xflow) <= 1e-9) then
            Tt = Ts
            return
        endif

        Qred = abs(xflow) * sqrt(Ts) / (A * pt)
        Tt = Ts * (1 + (Qred**2 / C**2))

        if (icase == 0) then
            TtzTs_crit = (kappa + 1.d0) / 2.d0
        else
            TtzTs_crit = (1d0 + (kappa - 1.d0) / (2.d0 * kappa))
        endif

        if (Tt / Ts > TtzTs_crit) then
            Tt = Ts * (TtzTs_crit + 1.d0) / 2.d0
        endif

        i = 0
        Tt_old = Tt
        condition = .true.
        do while (condition)
            i = i + 1
            Ttzts = Tt / Ts
            h1 = Ttzts - 1.d0
            h2 = sqrt(h1)
            h3 = Ttzts**expon
            f = C * h2 * h3
            df = 0.5d0 * abs(xflow) / (A * pt * sqrt(Tt)) - C * h2 * h3 * (expon / Tt + 1.d0 / (2.d0 * h1 * Ts))
            Qred = abs(xflow) * sqrt(Tt) / (A * pt)
            f = Qred - f
            deltaTt = -f / df
            Tt = Tt + deltaTt
            if ((abs(Tt - Tt_old) / Tt_old <= 1.d-8) .or. (abs(Tt - Tt_old) <= 1.d-10) .or. &
                (abs(f) <= 1d-5 .and. deltaTt < 1d-3)) then
                if (Tt / Ts > TtzTs_crit) then
                    Tt = Ts * TtzTs_crit
                endif
                exit
            elseif (i > 40) then
                Tt = 0.99d0 * Ts * TtzTs_crit
                exit
            endif
            Tt_old = Tt
        end do
    end subroutine tt_calc

end program test_tt_calc