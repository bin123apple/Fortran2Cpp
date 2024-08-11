program test_hrecur
  implicit none
  double precision :: pn, dpn, pn1, x
  integer :: nn

  ! Define test inputs
  x = 2.0d0
  nn = 5

  ! Call the subroutine
  call hrecur(pn, dpn, pn1, x, nn)

  ! Print the results
  print *, "pn:", pn
  print *, "dpn:", dpn
  print *, "pn1:", pn1

contains

  subroutine hrecur(pn, dpn, pn1, x, nn)
    implicit none
    double precision, intent(out) :: pn, dpn, pn1
    double precision, intent(in) :: x
    integer, intent(in) :: nn
    double precision :: p1, p, dp1, dp, fj, fj2, q, dq
    integer :: j

    p1 = 1.0d0
    p  = x
    dp1 = 0.0d0
    dp  = 1.0d0

    do j = 2, nn
      fj = dble(j)
      fj2 = 0.5d0*(fj-1.0d0)
      q  = x*p - fj2*p1
      dq = x*dp + p - fj2*dp1
      p1 = p
      p  = q
      dp1 = dp
      dp  = dq
    end do

    pn  = p
    dpn = dp
    pn1 = p1
  end subroutine hrecur

end program test_hrecur