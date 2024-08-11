program test_dgemv
  implicit none
  double precision, allocatable :: A(:,:), x(:), y(:)
  integer :: m, n
  character :: trans
  double precision :: alpha, beta
  integer :: lda, incx, incy

  ! Initialize variables
  trans = 'N'
  m = 2
  n = 3
  alpha = 1.0
  beta = 1.0
  lda = m
  incx = 1
  incy = 1

  allocate(A(m, n), x(n), y(m))

  ! A simple 2x3 matrix and a 3-element vector
  A(1, :) = [1.0, 2.0, 3.0]
  A(2, :) = [4.0, 5.0, 6.0]
  x = [1.0, 2.0, 3.0]
  y = [0.0, 0.0]

  ! Call the dgemv subroutine
  call dgemv(trans, m, n, alpha, A, lda, x, incx, beta, y, incy)

  ! Output the results
  print *, 'Result y:', y

end program test_dgemv

subroutine dgemv(trans, m, n, alpha, A, lda, x, incx, beta, y, incy)
  implicit none
  character*1, intent(in) :: trans
  integer, intent(in) :: m, n, lda, incx, incy
  double precision, intent(in) :: alpha, beta
  double precision, intent(in) :: A(lda, *)
  double precision, intent(in) :: x(*)
  double precision, intent(inout) :: y(*)
  integer :: i, j

  do i = 1, m
    do j = 1, n
      y(i) = y(i) + A(i, j) * x(j)
    end do
  end do
end subroutine dgemv