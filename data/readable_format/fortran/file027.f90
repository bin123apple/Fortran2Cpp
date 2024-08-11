program test_jgemmx
  implicit none
  ! Declare variables
  integer(KIND=8), parameter :: m = 2, n = 2, k = 2
  integer(KIND=8), parameter :: alpha = 1, beta = 1
  integer(KIND=8) :: a(m*n), b(m*n), c(m*n)
  integer(KIND=8) :: inc1a = 1, inc2a = 2, inc1b = 1, inc2b = 2, inc1c = 1, inc2c = 2
  integer :: i, j

  ! Initialize arrays a and b
  a = (/1, 2, 3, 4/)
  b = (/5, 6, 7, 8/)

  ! Call the subroutine
  call JGEMMX(m, n, k, alpha, a, inc1a, inc2a, b, inc1b, inc2b, beta, c, inc1c, inc2c)

  ! Check the results
  print *, "Results for C:"
  do i = 1, m
      do j = 1, n
          print *, "c(", i, ",", j, ") = ", c((i-1)*n+j)
      end do
  end do

contains

  subroutine JGEMMX(m, n, k, alpha, a, inc1a, inc2a, b, inc1b, inc2b, beta, c, inc1c, inc2c)
    integer(KIND=8), intent(in) :: m, n, k
    integer(KIND=8), intent(in) :: alpha, beta
    integer(KIND=8), intent(in) :: a(*), b(*)
    integer(KIND=8), intent(in) :: inc1a, inc2a, inc1b, inc2b
    integer(KIND=8), intent(inout) :: c(*)
    integer(KIND=8), intent(in) :: inc1c, inc2c
    ! Assuming the body of the subroutine simply copies 'a' to 'c' as a placeholder
    ! The actual implementation would likely be more complex
    integer :: i, j
    do i = 1, m
        do j = 1, n
            c((i-1)*n+j) = alpha * a((i-1)*n+j) + beta * b((i-1)*n+j)
        end do
    end do
  end subroutine JGEMMX

end program test_jgemmx