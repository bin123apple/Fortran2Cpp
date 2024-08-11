program test_rffti
  implicit none
  integer, parameter :: n = 8
  real*8 :: wsave(n)
  integer :: i
  real*8, parameter :: tol = 1.0e-7

  call rffti(n, wsave)

  ! Check a few key values with expected results
  if (abs(wsave(1) - cos(2 * atan(1.0) * 2 / n)) > tol) then
    print *, "Test failed for wsave(1)"
  else if (abs(wsave(n/2-1) - sin(2 * atan(1.0) * 2 / n)) > tol) then
    print *, "Test failed for wsave(n/2-1)"
  else
    print *, "All tests passed"
  end if

contains

  subroutine rffti(n,wsave)
    integer, intent(in) :: n
    real*8, dimension(n), intent(out) :: wsave
    integer :: ns2, nqm, k, kc
    real*8 :: tpi, dt, dc, ds

    ns2 = n / 2
    nqm = (ns2 - 1) / 2
    tpi = 8.0 * atan(1.0)
    dt = tpi / real(n)
    dc = cos(dt)
    ds = sin(dt)
    wsave(1) = dc
    wsave(ns2) = ds
    if (nqm < 2) return

    do k = 2, nqm
      kc = ns2 - k + 1
      wsave(k) = dc * wsave(k-1) - ds * wsave(kc)
      wsave(kc) = ds * wsave(k-1) + dc * wsave(kc)
    end do
  end subroutine rffti

end program test_rffti