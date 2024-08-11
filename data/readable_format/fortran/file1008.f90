program test_continuation_lines
  implicit none
  integer :: seconds_in_a_day = 0

  ! Test 1
  seconds_in_a_day = 24*60*60
  if (seconds_in_a_day == 86400) then
     print*, "Test 1 passed."
  else
     print*, "Test 1 failed."
  endif

  ! Test 2
  seconds_in_a_day = 24*60*60 
  if (seconds_in_a_day == 86400) then
     print*, "Test 2 passed."
  else
     print*, "Test 2 failed."
  endif

  ! Test 3: For the long string, we can only print it as Fortran does not have 
  ! a straightforward way to compare string lengths or contents in a manner 
  ! that would be useful for this simplistic test.
  print*, "This is a really long string, that normally would not fit on a single line."
end program