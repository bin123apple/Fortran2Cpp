program test_pr43337
  implicit none
  integer :: b(10), i, errors

  call pr43337(b)
  errors = 0

  do i = 1, 10
    if (b(i) /= 1) then
      print *, "Test failed at index:", i, "Value:", b(i)
      errors = errors + 1
    endif
  end do

  if (errors == 0) then
    print *, "All tests passed!"
  else
    print *, "There were", errors, "errors."
  endif
end program test_pr43337

subroutine pr43337(b)
  integer, intent(out) :: b(10)
  call foo(b)
  call bar(b)
contains
  subroutine foo(b)
    integer, intent(out) :: b(10)
    integer :: a
    do a = 1, 10
      b(a) = 1
    end do
  end subroutine foo

  subroutine bar(b)
    integer, intent(out) :: b(10)
    integer :: a
    do a = 1, 10
      b(a) = 1
    end do
  end subroutine bar
end subroutine pr43337