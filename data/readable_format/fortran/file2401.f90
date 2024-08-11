module mod1
contains
  function eval(func, x1)
    real :: eval, func, x1
    external :: func
    eval = func(x1)
  end function eval
end module mod1

module mod2
  use mod1, only : eval
  real, external :: extfunc
contains
  subroutine foo(x0)
    real :: x0, x1
    x1 = 42
    x0 = eval(extfunc, x1)
  end subroutine foo
end module mod2

function extfunc(x)
  real, intent(in) :: x
  real :: extfunc
  extfunc = x
end function extfunc

program test_program
  use mod2, only : foo
  real :: x0 = 0
  call foo(x0)
  print *, x0
  
  ! Test subroutine if needed
  call test_foo
contains
  subroutine test_foo
    real :: x0_test
    x0_test = 0
    call foo(x0_test)
    if (x0_test == 42.0) then
      print *, 'Test passed: x0_test =', x0_test
    else
      print *, 'Test failed: Expected 42.0, but got', x0_test
    endif
  end subroutine test_foo
end program test_program