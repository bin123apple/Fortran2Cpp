program test_kincaid_cheney
  implicit none
  double precision :: x, y, yd, p, t, s, error
  integer :: M, n

  x = 1.9
  M = 7
  y = x - sin(x)
  yd = dble(x) - sin(dble(x))
  p = (x**3/6.)*(1. - (x*x/20.)*(1. - (x*x/42.)*(1. - (x*x/72.))))

  t = x**3/6.0
  s = t
  error = abs((s - yd)/yd)

  ! Assuming these are the expected values from previous runs or calculations
  write(*,*) 'Testing with x =', x
  write(*,*) 'Expected yd:', yd
  write(*,*) 'Expected first s:', s
  write(*,*) 'Expected first error:', error

end program test_kincaid_cheney