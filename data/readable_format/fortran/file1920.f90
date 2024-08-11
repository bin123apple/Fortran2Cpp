program test_fcrit
  implicit none
  real*8 time,t,a,b,ze,d,dd,h1,h2,h3,h4,func,funcp

  ! Initialize test values
  time = 1.0
  t = 0.5
  a = 2.0
  b = 3.0
  ze = 0.0
  d = 0.0
  dd = 0.0
  h1 = 4.0
  h2 = 5.0
  h3 = 6.0
  h4 = 7.0

  ! Call the subroutine
  call fcrit(time, t, a, b, ze, d, dd, h1, h2, h3, h4, func, funcp)

  ! Print results
  print *, "func =", func
  print *, "funcp =", funcp
end program test_fcrit

subroutine fcrit(time,t,a,b,ze,d,dd,h1,h2,h3,h4,func,funcp)
  implicit none
  real*8 time,t,a,b,ze,d,dd,h1,h2,h3,h4,fexp,func,funcp

  fexp = dexp(-h1*t)
  func = ((a+b*time)*(-t*h2-h3)-b*(-t*t*h2-2.d0*t*h3-2.d0*h4))*fexp
  funcp = ((a+b*time)*t-b*(h3+t*h2+t*t))*fexp

  return
end subroutine fcrit