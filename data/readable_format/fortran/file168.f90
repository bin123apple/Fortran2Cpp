program test
  implicit none
  integer(8) :: foo(4294967296_8:4294967297_8)
  integer(8) :: bar(-4294967297_8:-4294967296_8)
  integer(8) :: lb, ub
  bar = 42
  foo = bar
  lb = lbound(foo, dim = 1, kind = 8)
  ub = ubound(foo, dim = 1, kind = 8)

  ! Test if bar is correctly initialized
  if (all(bar == 42)) then
      print *, 'Test 1 Passed: bar initialized correctly.'
  else
      print *, 'Test 1 Failed: bar not initialized correctly.'
  endif

  ! Test if values are copied from bar to foo
  if (all(foo == 42)) then
      print *, 'Test 2 Passed: Values copied from bar to foo correctly.'
  else
      print *, 'Test 2 Failed: Values not copied correctly.'
  endif

  ! Test bounds of foo
  if (lb == 4294967296_8 .and. ub == 4294967297_8) then
      print *, 'Test 3 Passed: Bounds of foo are correct.'
  else
      print *, 'Test 3 Failed: Bounds of foo are incorrect.'
  endif

end program test