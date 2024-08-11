program test_variable
  implicit none
  integer :: i = 10

  ! Check if the value of i is correct
  if (i == 10) then
    print *, "Test passed: i is 10"
  else
    print *, "Test failed: i is not 10"
  end if
end program test_variable