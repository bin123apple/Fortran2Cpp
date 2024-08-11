program dummy_array_test
  implicit none
  integer, dimension(10) :: a
  integer :: i
  logical :: test_passed
  
  call fill_array(a)
  
  test_passed = .TRUE.
  do i = 1, 10
    if (a(i) /= i) then
      test_passed = .FALSE.
      exit
    endif
  end do
  
  if (test_passed) then
    print*, "Test passed."
  else
    print*, "Test failed."
  endif
end program dummy_array_test

subroutine fill_array(a)
  implicit none
  integer, dimension(10), intent(out) :: a
  integer :: i
  
  do i = 1, 10
    a(i) = i
  end do
end subroutine fill_array