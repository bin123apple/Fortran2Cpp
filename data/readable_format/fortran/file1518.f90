program test_abs
  implicit none
  real, dimension(2) :: a, b
  integer :: i
  logical :: test_passed
  
  ! Initialize test data
  a(1) = -3.5
  a(2) = 4.5
  b = 0.0  ! Initialize b to ensure clean slate
  
  ! Expected operation
  do i = 1, 2
    b(i) = abs(a(i))
  end do
  
  ! Test
  test_passed = .true.
  if (b(1) /= 3.5 .or. b(2) /= 4.5) then
    test_passed = .false.
  end if
  
  ! Report results
  if (test_passed) then
    print *, "Test Passed"
  else
    print *, "Test Failed"
  end if
  
end program test_abs