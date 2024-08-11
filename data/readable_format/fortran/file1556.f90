module bratu2d_mod
  implicit none
contains
  subroutine bratu2d(m, n, alpha, x, f)
    integer, intent(in) :: m, n
    real(kind=8), intent(in) :: alpha
    real(kind=8), dimension(m,n), intent(in) :: x
    real(kind=8), dimension(m,n), intent(inout) :: f
    integer :: i, j
    real(kind=8) :: hx, hy, u, uN, uS, uE, uW

    hx = 1.0d0 / (m - 1)
    hy = 1.0d0 / (n - 1)
    f = x

    do i = 2, m - 1
      do j = 2, n - 1
        u = x(i,j)
        uN = x(i-1,j)
        uS = x(i+1,j)
        uE = x(i,j+1)
        uW = x(i,j-1)

        f(i,j) = (2.0d0*u - uE - uW) * (hy/hx) + &
                 (2.0d0*u - uN - uS) * (hx/hy) - &
                 alpha * exp(u) * (hx * hy)
      end do
    end do
  end subroutine bratu2d
end module bratu2d_mod

program test_bratu2d
  use bratu2d_mod
  implicit none
  integer, parameter :: m = 5, n = 5
  real(kind=8) :: alpha = 1.0
  real(kind=8), dimension(m,n) :: x, f
  integer :: i, j

  ! Initialize x with some simple values for testing
  do i = 1, m
    do j = 1, n
      x(i, j) = sin(real(i*j, kind=8))
    end do
  end do

  ! Call the subroutine
  call bratu2d(m, n, alpha, x, f)

  ! Output the results for manual verification
  print *, "Results for f:"
  do i = 1, m
    print *, f(i, :)
  end do

end program test_bratu2d