program test_open_files
  implicit none
  integer :: i, ios
  logical :: test_passed
  test_passed = .TRUE.

  do i = 1, 30
    open(100+i, status="scratch", iostat=ios)
    if (ios /= 0) then
      print *, "Test failed on iteration: ", i
      test_passed = .FALSE.
      exit
    endif
  end do

  if (test_passed) then
    print *, "All tests passed successfully."
  else
    print *, "Some tests failed."
  endif
end program test_open_files