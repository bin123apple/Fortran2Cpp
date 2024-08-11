module ksdmod
  implicit none
contains
  subroutine ksd(df, g, dgdx, ng, rho)
    implicit double precision (a-h,o-z)
    dimension g(ng),dgdx(ng)
    double precision df, rho
    integer ng
    double precision sum1, sum2, gmax, val
    integer i
    data toler /-40.0/

    sum1 = 0.0
    sum2 = 0.0
    gmax = g(1)
    if (ng .lt. 2) go to 30
    do 10 i = 2,ng
      if (g(i) .gt. gmax) gmax = g(i)
10   continue
    do 20 i = 1,ng
      val = rho * (g(i) - gmax)
      if (val .lt. toler) go to 20
      sum1 = sum1 + exp(val) * dgdx(i)
      sum2 = sum2 + exp(val)
20   continue
30   continue
    df = dgdx(1)
    if (ng .gt. 1) df = sum1 / sum2
    return
  end subroutine ksd
end module ksdmod

program testksd
  use ksdmod
  implicit none
  double precision df, rho
  double precision g(3), dgdx(3)
  integer ng

  rho = 1.0
  g = (/ 1.0, 2.0, 3.0 /)
  dgdx = (/ 0.1, 0.2, 0.3 /)
  ng = 3

  call ksd(df, g, dgdx, ng, rho)

  print *, "Computed df: ", df
end program testksd