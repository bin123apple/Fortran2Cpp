program test_x_wc06
    implicit none
    real(8) :: rho, s, u, v, ex, vx

    ! Example test case
    rho = 1.0d0
    s = 0.5d0
    u = 0.2d0
    v = 0.1d0

    call x_wc06(rho, s, u, v, ex, vx)

    print *, "Actual ex: ", ex
    print *, "Actual vx: ", vx
end program test_x_wc06

subroutine x_wc06(rho, s, u, v, ex, vx)
    implicit none
    real(8), intent(in) :: rho, s, u, v
    real(8), intent(out) :: ex, vx
    real(8), parameter :: ax=-0.7385587663820224059d0
    real(8), parameter :: mu=0.2195149727645171d0
    real(8), parameter :: kappa=0.804d0
    real(8), parameter :: b=10.d0/81.d0
    real(8), parameter :: c=0.00793746933516d0
    real(8), parameter :: thrd=1.d0/3.d0
    real(8), parameter :: thrd4=4.d0/3.d0
    real(8) :: dmu, exu
    real(8) :: s2, s4, es2, x, p0, fxwc
    real(8) :: fs, fss, t0, t1, t2, t3

    exu = ax * rho**thrd
    s2 = s**2
    s4 = s2**2
    es2 = exp(-s2)
    t0 = 1.d0 + c * s4
    dmu = mu - b
    x = b * s2 + dmu * s2 * es2 + log(t0)
    p0 = 1.d0 + x / kappa
    fxwc = 1.d0 + kappa - kappa / p0
    ex = exu * fxwc

    t1 = b + dmu * (1.d0 - s2) * es2 + 2.d0 * c * s2 / t0
    t2 = dmu * s * (s2 - 2.d0) * es2 + 2.d0 * c / t0 - 4.d0 * (c**2) * s4 / (t0**2)
    t3 = 1.d0 / (p0**2)
    fs = 2.d0 * t1 * t3
    fss = t3 * (4.d0 * t2 - 8.d0 * s * (t1**2) / (kappa * p0))
    vx = exu * (thrd4 * fxwc - (u - thrd4 * s2 * s) * fss - v * fs)
end subroutine x_wc06