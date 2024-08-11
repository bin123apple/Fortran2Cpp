module foo
contains
  function pop(n) result(item)
    integer :: n
    character(len=merge(1, 0, n > 0)) :: item
  end function pop

  function push(n) result(item)
    integer :: n
    character(len=merge(1, 0, n /= 0)) :: item
  end function push
end module foo

program test
  use foo
  if (len(pop(0)) /= 0) call abort()
  if (len(pop(1)) /= 1) call abort()
  if (len(push(0)) /= 0) call abort()
  if (len(push(1)) /= 1) call abort()
  print *, "All tests passed!"
end program test