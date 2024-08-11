program test_a
  implicit none
  integer, parameter :: i(4) = (/ 1, 1, 1, 1 /)
  integer :: z(4) = (/ 1, 1, -1, -1 /)
  integer :: test_case
  logical :: test_passed
  
  ! Apply transformation
  where(z < 0) z(:) = 1
  
  ! Test case: Check if z equals i after transformation
  test_case = 1
  test_passed = .true.
  do test_case=1, size(z)
      if (z(test_case) /= i(test_case)) then
          test_passed = .false.
          exit
      endif
  end do
  
  if (test_passed) then
      print *, "Test Passed!"
  else
      print *, "Test Failed!"
      stop 1
  endif
end program test_a