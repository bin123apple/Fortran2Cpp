program test_ts_calc
    implicit none
    double precision :: Ts, xflow, Tt, Pt, kappa, r, a
    integer :: icase

    ! Example test case 1
    xflow = 0.5d0
    Tt = 300.0d0
    Pt = 101325.0d0
    kappa = 1.4d0
    r = 287.0d0
    a = 340.0d0
    icase = 0
    call ts_calc(xflow, Tt, Pt, kappa, r, a, Ts, icase)
    print *, "Test Case 1: Ts =", Ts

    ! Add more test cases as needed, providing expected output and comparing results

contains

    subroutine ts_calc(xflow, Tt, Pt, kappa, r, a, Ts, icase)
        implicit none
        double precision, intent(in) :: xflow, Tt, Pt, kappa, r, a
        double precision, intent(inout) :: Ts
        integer, intent(in) :: icase
        double precision :: expon, C, Ts_old, deltaTs, TtzTs, Qred, Qred_crit, TtzTs_crit, f, df, h1, h2, h3
        integer :: i, inv

        expon = -0.5d0 * (kappa + 1.d0) / (kappa - 1.d0)
        C = dsqrt(2.d0 / r * kappa / (kappa - 1.d0))
        Ts_old = Tt
        if (xflow < 0d0) then
            inv = -1
        else
            inv = 1
        endif
        if (abs(xflow) <= 1e-9) then
            Ts = Tt
            return
        endif
        Qred = abs(xflow) * dsqrt(Tt) / (a * Pt)
        Ts = Tt / (1 + (Qred**2 / C**2))
        if (icase == 0) then
            TtzTs_crit = (kappa + 1.d0) / 2.d0
        else
            TtzTs_crit = (1d0 + (kappa - 1.d0) / (2.d0 * kappa))
        endif
        Qred_crit = C * (TtzTs_crit)**expon * dsqrt(TtzTs_crit - 1.d0)
        if (Qred >= Qred_crit) then
            Ts = Tt / TtzTs_crit
            return
        endif
        i = 0
        do
            i = i + 1
            TtzTs = Tt / Ts
            h1 = TtzTs - 1.d0
            h2 = dsqrt(h1)
            h3 = TtzTs**expon
            f = C * h2 * h3
            df = f * (expon + 0.5d0 * TtzTs / h1) / Ts
            f = Qred - f
            deltaTs = -f / df
            Ts = Ts + deltaTs
            if (abs(Ts - Ts_old) / Ts_old <= 1.E-8 .or. abs(Ts - Ts_old) <= 1.E-10) exit
            if (i > 20) then
                Ts = 0.9 * Tt
                exit
            endif
            Ts_old = Ts
        enddo
    end subroutine ts_calc

end program test_ts_calc