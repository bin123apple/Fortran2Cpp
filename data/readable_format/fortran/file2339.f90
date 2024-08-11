program test_fortran
  call test
  print *, 'Test passed!'
end program test_fortran

subroutine test
  integer i(1000000), j
  equivalence (i(50), j)

  j = 1
  if (i(50) /= j) STOP 1
end subroutine test