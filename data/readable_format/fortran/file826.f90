program test_repeat
  character, parameter :: z = 'z'
  character(len=3) :: expected_output
  character(len=:), allocatable :: actual_output
  
  expected_output = "zzz"
  actual_output = repeat(z, 3)
  
  if (actual_output == expected_output) then
    print *, "Test passed."
  else
    print *, "Test failed."
  endif
end program test_repeat