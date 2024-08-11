program test
  implicit none
  integer(1) :: i
  integer(1) :: expected_values(11)
  integer :: j
  logical :: test_passed ! Use logical instead of integer for test_passed

  ! Initialize expected values for testing
  do j = 1, 11
     expected_values(j) = HUGE(i) - 11 + j
  end do

  j = 1
  test_passed = .true.
  do i = HUGE(i)-10, HUGE(i)
    if (i /= expected_values(j)) then
       test_passed = .false.
       exit
    end if
    j = j + 1
  end do

  if (test_passed) then
     print *, "Test passed: Iteration matches expected values."
  else
     print *, "Test failed: Iteration does not match expected values."
  end if
end program test