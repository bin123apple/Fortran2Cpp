program tester
  implicit none
  character(50) cname, fred
  integer kk
  
  ! Test case 1
  fred='1234567890123456789012345678901234567890'
  kk=len_trim(fred)
  cname=fred(5:kk)
  if (kk == 40 .and. cname == '567890123456789012345678901234567890') then
     print *, 'Test 1 Passed'
  else
     print *, 'Test 1 Failed'
  end if
  
end program tester