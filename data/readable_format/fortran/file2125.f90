program test_foo
  call foo()
  print *, "Test passed."
contains
  subroutine foo()
    integer, target :: A(30)
    integer, pointer :: p(:)
    p => A
    A(3) = 777
    p(9) = 777
    A(9) = 999
    if (A(3) /= 777 .or. A(9) /= 999) stop 1
  end subroutine
end program test_foo