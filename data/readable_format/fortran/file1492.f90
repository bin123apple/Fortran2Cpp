module foo_fixed
  contains
    subroutine bar12(a)
      integer, intent(inout) :: a
      a = 12
    end subroutine bar12
end module foo_fixed

program test_foo_fixed
  use foo_fixed
  implicit none
  integer :: a
  
  a = 0
  call bar12(a)
  
  if (a == 12) then
    print *, "Test passed: a = ", a
  else
    print *, "Test failed: a = ", a
  end if
end program test_foo_fixed