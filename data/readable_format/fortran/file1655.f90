module d
  integer::i=3
end module d

program test_d
  use d
  if (i == 3) then
    print *, "Test passed: i = 3"
  else
    print *, "Test failed: i /= 3"
  end if
end program test_d