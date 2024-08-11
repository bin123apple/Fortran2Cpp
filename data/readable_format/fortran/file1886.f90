program testFoo
  implicit none
  integer :: result1, result2

  result1 = foo()
  if (result1 /= 1) then
    print *, "Test failed: Expected foo() to return 1, got ", result1
    call abort()
  end if

  result2 = foo()
  if (result2 /= 2) then
    print *, "Test failed: Expected foo() to return 2, got ", result2
    call abort()
  end if

  print *, "All tests passed."

contains

  integer function foo()
    integer, save :: i = 0
    i = i + 1
    foo = i
  end function foo

end program testFoo