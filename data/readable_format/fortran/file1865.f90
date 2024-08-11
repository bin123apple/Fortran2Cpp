module m
  implicit none
contains

subroutine foo(a, b)
  integer, intent(in) :: a, b
  logical, save :: was_foo = .false.
  if ((a .ne. 3) .or. (b .ne. 4)) call abort()
  was_foo = .true.
end subroutine foo

subroutine bar(a)
  integer, intent(in) :: a
  logical, save :: was_foo = .false.
  if (a .ne. 5) call abort()
  was_foo = .false.
end subroutine bar

subroutine indirecta(p)
  interface
    subroutine p(a, b)
      integer, intent(in) :: a, b
    end subroutine p
  end interface
  call p(3, 4)
end subroutine indirecta

subroutine indirectb(p)
  interface
    subroutine p(a)
      integer, intent(in) :: a
    end subroutine p
  end interface
  call p(5)
end subroutine indirectb

subroutine test1
  call indirecta(foo)
  call indirectb(bar)
end subroutine test1

subroutine test2
  call foo(3, 4)
  call bar(5)
end subroutine test2

end module m

program test
  use m
  call test1()
  call test2()
  print *, 'All tests passed successfully.'
end program test