program foo
  implicit none
  logical :: b

  ! Test 1: Check b eqv b (which should always be true)
  b = .true.
  b = b .eqv. b
  if (b) then
    print *, "Test 1 passed: b eqv b is true as expected."
  else
    print *, "Test 1 failed: b eqv b is not true."
  endif

  ! Test 2: Check b neqv b (which should always be false)
  b = .true.
  b = b .neqv. b
  if (.not. b) then
    print *, "Test 2 passed: b neqv b is false as expected."
  else
    print *, "Test 2 failed: b neqv b is not false."
  endif

end program foo