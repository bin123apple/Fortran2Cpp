program test_math_functions
  implicit none
  double precision :: x, y, t
  double precision :: result

  ! Test values
  x = 0.5
  y = -0.4
  t = 1.0

  ! Testing exau
  result = exau(x, y, t)
  print *, "exau(", x, ",", y, ",", t, ") = ", result

  ! Testing exav
  result = exav(x, y, t)
  print *, "exav(", x, ",", y, ",", t, ") = ", result

  ! Testing exap
  result = exap(x, y, t)
  print *, "exap(", x, ",", y, ",", t, ") = ", result

contains

  function exau(x,y,t)
    double precision, intent(in) :: x, y, t
    double precision :: exau
    exau = -exp(-2*t)*cos(x)*sin(y)
  end function exau

  function exav(x,y,t)
    double precision, intent(in) :: x, y, t
    double precision :: exav
    exav = exp(-2*t)*sin(x)*cos(y)
  end function exav

  function exap(x,y,t)
    double precision, intent(in) :: x, y, t
    double precision :: exap
    exap = -0.25*exp(-4*t)*(cos(2*x)+cos(2*y))
  end function exap

end program test_math_functions