module file1
  implicit none
  real :: dist1 = 10
end module file1

program test_file1
  use file1
  implicit none

  print *, 'Testing dist1 from file1 module...'
  if (dist1 == 10) then
    print *, 'Test passed: dist1 is initialized correctly.'
  else
    print *, 'Test failed: dist1 is NOT initialized correctly.'
  endif
end program test_file1