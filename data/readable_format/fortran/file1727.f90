! test_t.f90
program test_t
  implicit none
  integer :: i
  
  ! Test 1
  i = 1
  if (1.lt.2) i=3
  if (i == 3) then
    print *, "Test 1 passed."
  else
    print *, "Test 1 failed."
  end if
  
  ! Add more tests as needed

end program test_t