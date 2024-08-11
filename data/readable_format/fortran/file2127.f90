program test_foo
  implicit none

  call foo()

contains

  subroutine foo()
    print *, 'foo() called'
  end subroutine foo

end program test_foo