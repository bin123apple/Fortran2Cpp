program test_trdisb
  implicit none
  double precision a(3), b(3), c(3), d(3)
  integer n

  n = 3
  a = (/1.0, 2.0, 3.0/)
  b = (/4.0, 5.0, 6.0/)
  c = (/7.0, 8.0, 9.0/)
  d = (/10.0, 11.0, 12.0/)

  call trdisb(n, a, b, c, d)

  print *, 'Modified d:', d

contains

  subroutine trdisb(n, a, b, c, d)
    implicit none
    double precision, intent(in) :: a(*), b(*), c(*)
    double precision, intent(inout) :: d(*)
    integer, intent(in) :: n
    integer :: k, km1

    d(1) = d(1) / b(1)
    do k = 2, n
      km1 = k - 1
      d(k) = (d(k) - a(km1) * d(km1)) / b(k)
    end do
    do k = n - 1, 1, -1
      d(k) = d(k) - c(k) * d(k + 1)
    end do
  end subroutine trdisb

end program test_trdisb