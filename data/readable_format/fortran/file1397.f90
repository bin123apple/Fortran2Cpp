! test_where_construct2.f90
program test_where_construct2
  implicit none
  integer, parameter :: N = 7
  real :: a(N,N), b(N,N)
  real :: threshold = 0.5
  logical :: test_passed
  integer :: i, j

  ! Generate a test case where a is explicitly set for predictability
  a = reshape([ (0.1 * i, i=1,N*N) ], [N, N])
  b = 0.0

  ! Expected behavior: b(i,j) should be 0.0 if a(i,j) <= threshold, else a(i,j)
  where (a > threshold) b = a

  ! Check if the behavior is as expected
  test_passed = .true.
  do i = 1, N
     do j = 1, N
        if (a(i,j) > threshold .and. b(i,j) /= a(i,j)) then
           test_passed = .false.
        else if (a(i,j) <= threshold .and. b(i,j) /= 0.0) then
           test_passed = .false.
        end if
     end do
  end do

  if (test_passed) then
     print *, "Test passed."
  else
     print *, "Test failed."
  end if

end program test_where_construct2