program test
  integer :: nums(2)
  integer :: i
  logical :: test_passed

  test_passed = .TRUE.
  do i = 1, 2
    nums(i) = i + 47
    if (nums(i) /= i + 47) then
      test_passed = .FALSE.
      exit
    endif
  enddo

  if (test_passed) then
    print *, "Test passed: the array contains the correct values."
  else
    print *, "Test failed: the array does not contain the expected values."
  endif

end program test