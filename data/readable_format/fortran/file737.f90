Program test_si_kind
  implicit none
  integer*1 i1
  integer*2 i2
  integer*4 i4
  integer*8 i8
  integer res
  real t

  ! Test 1
  t = huge(i1)
  t = log10(t)
  res = selected_int_kind(int(t))
  if (res .ne. 1) then
    print *, 'Test 1 Failed'
  else
    print *, 'Test 1 Passed'
  endif

  ! Test 2
  t = huge(i2)
  t = log10(t)
  res = selected_int_kind(int(t))
  if (res .ne. 2) then
    print *, 'Test 2 Failed'
  else
    print *, 'Test 2 Passed'
  endif

  ! Test 3
  t = huge(i4)
  t = log10(t)
  res = selected_int_kind(int(t))
  if (res .ne. 4) then
    print *, 'Test 3 Failed'
  else
    print *, 'Test 3 Passed'
  endif

  ! Test 4
  t = huge(i8)
  t = log10(t)
  res = selected_int_kind(int(t))
  if (res .ne. 8) then
    print *, 'Test 4 Failed'
  else
    print *, 'Test 4 Passed'
  endif

  ! Special case test
  i4 = huge(i4)
  res = selected_int_kind(i4)
  if (res .ne. (-1)) then
    print *, 'Special Case Test Failed'
  else
    print *, 'Special Case Test Passed'
  endif

end program