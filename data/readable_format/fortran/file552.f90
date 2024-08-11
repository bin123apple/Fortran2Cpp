program test
  implicit none
  logical :: test_result

  test_result = .not..true.
  if (test_result .eqv. .false.) then
    print *, "Test 1 passed"
  else
    print *, "Test 1 failed"
  end if

  test_result = .not..false.
  if (test_result .eqv. .true.) then
    print *, "Test 2 passed"
  else
    print *, "Test 2 failed"
  end if

  test_result = .not..false..eqv..true.
  if (test_result .eqv. .true.) then
    print *, "Test 3 passed"
  else
    print *, "Test 3 failed"
  end if

  if ('hello' .eq. 'hello') then
    print *, "Test 4 passed"
  else
    print *, "Test 4 failed"
  end if

  if ('hello' .eq. 'world') then
    print *, "Test 5 failed"
  else
    print *, "Test 5 passed"
  end if

  if ('hello world' == 'hello' // ' world') then
    print *, "Test 6 passed"
  else
    print *, "Test 6 failed"
  end if

end program test