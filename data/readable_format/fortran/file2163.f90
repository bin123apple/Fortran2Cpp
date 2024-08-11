module x_pbe_module
implicit none
contains

subroutine x_pbe(kappa, mu, rho, s, u, v, ex, vx)
  implicit none
  real(8), intent(in) :: kappa, mu, rho, s, u, v
  real(8), intent(out) :: ex, vx
  real(8), parameter :: pi = 3.1415926535897932385d0
  real(8), parameter :: ax = -0.7385587663820224058d0
  real(8), parameter :: thrd = 1.d0 / 3.d0
  real(8), parameter :: thrd4 = 4.d0 / 3.d0
  real(8) :: ul, exu, s2, p0, fxpbe, fs, fss
  
  ul = mu / kappa
  exu = ax * rho**thrd
  s2 = s**2
  p0 = 1.d0 + ul * s2
  fxpbe = 1.d0 + kappa - kappa / p0
  ex = exu * fxpbe
  fs = 2.d0 * kappa * ul / (p0 * p0)
  fss = -4.d0 * ul * s * fs / p0
  vx = exu * (thrd4 * fxpbe - (u - thrd4 * s2 * s) * fss - v * fs)
end subroutine x_pbe

end module x_pbe_module

program test_x_pbe
  use x_pbe_module
  implicit none
  real(8) :: kappa, mu, rho, s, u, v, ex, vx

  ! Example test values
  kappa = 0.5d0
  mu = 0.3d0
  rho = 1.0d0
  s = 0.2d0
  u = 0.1d0
  v = 0.05d0

  call x_pbe(kappa, mu, rho, s, u, v, ex, vx)

  print *, 'Fortran ex = ', ex
  print *, 'Fortran vx = ', vx
end program test_x_pbe