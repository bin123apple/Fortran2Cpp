program test_cd_ms_ms
    implicit none

    double precision :: p1, p2, T1, rad, d, xl, kappa, r, reynolds, u, vid, cd

    ! Initialize test variables
    p1 = 1.0d0
    p2 = 0.5d0
    T1 = 300.0d0
    rad = 0.1d0
    d = 0.05d0
    xl = 0.15d0
    kappa = 1.4d0
    r = 287.0d0
    reynolds = 10000.0d0
    u = 50.0d0
    vid = 0.0d0
    cd = 0.0d0

    ! Call the subroutine
    call cd_ms_ms(p1, p2, T1, rad, d, xl, kappa, r, reynolds, u, vid, cd)

    ! Print the results
    print *, 'vid = ', vid
    print *, 'cd = ', cd

end program test_cd_ms_ms

subroutine cd_ms_ms(p1, p2, T1, rad, d, xl, kappa, r, reynolds, u, vid, cd)
    implicit none 

    double precision :: p1, p2, T1, rad, d, xl, kappa, r, reynolds, u, vid, cd
    double precision :: qlim, q, c1, c2, c3, fakt, aux, rzd, lkorr, qkorr, rv

    qlim = 10.0d0

    cd = 0.5885d0 + 372.d0 / reynolds
    cd = min(cd, 1.d0)

    rzd = rad / d
    aux = exp(-(3.5d0 * rzd + 5.5d0) * rzd)
    fakt = aux + 0.008d0 * (1.d0 - aux)
    cd = 1.d0 - fakt * (1.d0 - cd)
    cd = min(max(cd, 0.d0), 1.d0)

    lkorr = xl - rad
    q = lkorr / d
    qkorr = min(q, qlim)
    fakt = (1.d0 + 1.3d0 * exp(-1.606d0 * qkorr**2.d0)) * (0.435d0 + 0.021d0 * qkorr) / (2.3d0 * 0.435d0)
    cd = 1.d0 - fakt * (1.d0 - cd)
    cd = min(max(cd, 0.d0), 1.d0)

    if (u .ne. 0d0) then
        vid = sqrt(2.d0 * kappa / (kappa - 1.d0) * r * T1 * (1.d0 - (p2 / p1)**((kappa - 1.d0) / kappa)))
        rv = u / vid * (0.6d0 / cd)**3
        c1 = exp(-rv**1.2d0)
        c2 = 0.5d0 * rv**0.6d0 * sqrt(0.6d0 / cd)
        c3 = exp(-0.5d0 * rv**0.9d0)
        cd = cd * (c1 + c2 * c3)
        cd = min(max(cd, 0.d0), 1.d0)
    endif
end subroutine cd_ms_ms