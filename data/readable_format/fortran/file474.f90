module tt_calc_module
  implicit none
contains
  subroutine tt_calc(xflow, Tt, Pt, kappa, r, A, Ts, icase)
    implicit none
    integer :: icase
    double precision :: xflow, Tt, Pt, Ts, kappa, r, A
    double precision :: f, df, expon, Tt_old, C, TtzTs, deltaTt, TtzTs_crit, Qred, h1, h2, h3
    integer :: i
    expon = -0.5d0 * (kappa + 1.d0) / (kappa - 1.d0)
    C = sqrt(2.d0 / r * kappa / (kappa - 1.d0))
    if (abs(xflow) <= 1e-9) then
      Tt = Ts
      return
    endif
    Qred = abs(xflow) * sqrt(Ts) / (A * Pt)
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
    do
      i = i + 1
      TtzTs = Tt / Ts
      h1 = TtzTs - 1.d0
      h2 = sqrt(h1)
      h3 = TtzTs**expon
      f = C * h2 * h3
      df = 0.5 * abs(xflow) / (A * Pt * sqrt(Tt)) - C * h2 * h3 * (expon / Tt + 1.d0 / (2.d0 * h1 * Ts))
      Qred = abs(xflow) * sqrt(Tt) / (A * Pt)
      f = Qred - f
      deltaTt = -f / df
      Tt = Tt + deltaTt
      if ((abs(Tt - Tt_old) / Tt_old <= 1.E-8) .or. (abs(Tt - Tt_old) <= 1.E-10) .or. (abs(f) <= 1E-5 .and. deltaTt < 1E-3)) then
        if (Tt / Ts > TtzTs_crit) then
          Tt = Ts * TtzTs_crit
        endif
        exit
      else if (i > 40) then
        Tt = 0.99 * Ts * TtzTs_crit
        exit
      endif
      Tt_old = Tt
    end do
  end subroutine tt_calc
end module tt_calc_module

program test
  use tt_calc_module
  implicit none
  double precision :: xflow, Tt, Pt, Ts, kappa, r, A
  integer :: icase

  ! Set test values
  xflow = 0.02
  Pt = 1.0
  kappa = 1.4
  r = 287.0
  A = 1.0
  Ts = 300.0
  icase = 0

  ! Call the subroutine
  call tt_calc(xflow, Tt, Pt, kappa, r, A, Ts, icase)

  ! Output the result
  print *, "Fortran Test Case - Tt: ", Tt
end program test