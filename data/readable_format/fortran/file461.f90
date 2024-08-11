program testFoo
  call foo
  print *, 'Test passed.'
end program testFoo

subroutine foo
  integer, save :: a
  integer :: b
  equivalence (a, b)
  a = 5
  if (b.ne.5) stop 'Test failed: b is not equal to 5.'
  b = 10
  if (a.ne.10) stop 'Test failed: a is not equal to 10 after setting b to 10.'
end subroutine