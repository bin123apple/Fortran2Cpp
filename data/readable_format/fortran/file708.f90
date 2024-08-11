program test_kind
  print *, "Test: kind of integer q(3)"
  print *, "Expected: ", selected_int_kind(15)
  print *, "Got: ", kind(0)
  if (kind(0) == selected_int_kind(15)) then
     print *, "Test Passed"
  else
     print *, "Test Failed"
  end if
end program test_kind