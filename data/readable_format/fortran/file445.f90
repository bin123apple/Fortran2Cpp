module dpowint_mod
  implicit none
contains
  double precision function dpowint(xlow, xhigh, ylow, yhigh, xval, pow)
    implicit none
    double precision, intent(in) :: xlow, xhigh, ylow, yhigh, xval, pow
    double precision :: EPSLON
    EPSLON = 1.0D-20

    if (abs(xhigh-xlow) < EPSLON) then
      dpowint = (yhigh + ylow) / 2.0D0
    else
      dpowint = ylow + (yhigh - ylow) * &
                ((xval - xlow) / (xhigh - xlow))**pow
    endif
  end function dpowint
end module dpowint_mod

program test_dpowint
  use dpowint_mod
  implicit none
  double precision :: result

  ! Test cases
  result = dpowint(1.0D0, 1.0D0, 2.0D0, 3.0D0, 1.5D0, 2.0D0)
  print *, 'Test 1 (xlow == xhigh): ', result

  result = dpowint(1.0D0, 2.0D0, 2.0D0, 4.0D0, 1.5D0, 1.0D0)
  print *, 'Test 2 (Linear): ', result

  result = dpowint(0.0D0, 10.0D0, 0.0D0, 100.0D0, 5.0D0, 2.0D0)
  print *, 'Test 3 (Mid-range xval): ', result
end program test_dpowint