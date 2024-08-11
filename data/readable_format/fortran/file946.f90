program test_ksd
  implicit none
  double precision df
  double precision, allocatable :: g(:), dgdx(:)
  integer ng
  double precision rho
  ! Test data
  ng = 3
  rho = 0.5
  allocate(g(ng), dgdx(ng))
  g(1) = 1.0
  g(2) = 2.0
  g(3) = 3.0
  dgdx(1) = 0.1
  dgdx(2) = 0.2
  dgdx(3) = 0.3
  ! Call the subroutine
  call ksd(df, g, dgdx, ng, rho)
  ! Output the result and compare with expected value
  print *, "Computed df:", df
  print *, "Expected df: 0.279508497"
end program test_ksd

subroutine ksd (df,g,dgdx,ng,rho)
  implicit double precision (a-h,o-z)
  dimension g(ng),dgdx(ng)
  data toler /-40.0/
  double precision sum1, sum2, gmax, val
  integer i
  sum1 = 0.0
  sum2 = 0.0
  gmax = g(1)
  if (ng .lt. 2) goto 30
  do 10 i = 2,ng
    if (g(i) .gt. gmax) gmax = g(i)
10 continue
  do 20 i = 1,ng
    val = rho * (g(i) - gmax)
    if (val .lt. toler) goto 20
    sum1 = sum1 + exp(val) * dgdx(i)
    sum2 = sum2 + exp(val)
20 continue
30 continue
  df = dgdx(1)
  if (ng .gt. 1) df = sum1 / sum2
  return
end