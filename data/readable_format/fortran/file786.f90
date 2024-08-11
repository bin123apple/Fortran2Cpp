! test_truc.f90
module truc
  integer, parameter :: answer = 42
contains
end module truc

program test_truc
  use truc
  implicit none
  
  if (answer == 42) then
    print *, "Test passed: answer is 42"
  else
    print *, "Test failed: answer is not 42"
  end if
end program test_truc