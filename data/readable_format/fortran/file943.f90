program main
  implicit none
  integer, parameter :: n = 32
  real :: a(n), b(n)
  integer :: i
  logical :: test_passed

  ! Initialize arrays
  do i = 1, n
    a(i) = 1.0
    b(i) = 0.0
  end do

  ! First modification and test
  do i = 1, n
    b(i) = 2.0
    a(i) = a(i) + b(i)
  end do

  ! Test the results
  test_passed = .true.
  do i = 1, n
    if (a(i) /= 3.0 .or. b(i) /= 2.0) then
      test_passed = .false.
      exit
    endif
  end do

  if (test_passed) then
    print *, 'Test 1 passed: a(i) is 3.0 and b(i) is 2.0 for all i.'
  else
    print *, 'Test 1 failed.'
  endif

  ! Second modification and test
  do i = 1, n
    b(i) = 3.0
    a(i) = a(i) + b(i)
  end do

  ! Test the results
  test_passed = .true.
  do i = 1, n
    if (a(i) /= 6.0 .or. b(i) /= 3.0) then
      test_passed = .false.
      exit
    endif
  end do

  if (test_passed) then
    print *, 'Test 2 passed: a(i) is 6.0 and b(i) is 3.0 for all i.'
  else
    print *, 'Test 2 failed.'
  endif

end program main