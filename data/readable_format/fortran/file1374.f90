program test
  implicit none
  integer, parameter :: N = 8
  real, allocatable :: a(:), b(:)
  integer :: i

  allocate (a(N))
  allocate (b(N))

  a(:) = 3.0
  b(:) = 0.0

  ! Test initial assignment
  do i = 1, N
    if (a(i) /= 3.0) then
      print *, "Test failed: Initial assignment to a(i) is incorrect."
      stop
    endif
    if (b(i) /= 0.0) then
      print *, "Test failed: Initial assignment to b(i) is incorrect."
      stop
    endif
  end do
  print *, "Test passed: Initial assignment to a and b is correct."

  ! Simulate parallel assignment
  do i = 1, N
    b(i) = a(i)
  end do

  ! Test parallel assignment
  do i = 1, N
    if (b(i) /= 3.0) then
      print *, "Test failed: Parallel assignment to b(i) from a(i) is incorrect."
      stop
    endif
  end do
  print *, "Test passed: Parallel assignment to b from a is correct."

  ! Update and test again
  a(:) = 5.0
  b(:) = 1.0

  ! Simulate parallel assignment again
  do i = 1, N
    b(i) = a(i)
  end do

  ! Test final result
  do i = 1, N
    if (a(i) /= 5.0 .or. b(i) /= 5.0) then
      print *, "Test failed: Final values of a(i) or b(i) are incorrect."
      stop
    endif
  end do
  print *, "Test passed: Final values of a and b are correct."

end program test