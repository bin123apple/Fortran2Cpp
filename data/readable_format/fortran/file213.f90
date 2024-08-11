program test
  call test_foo
  call test_bar
  print *, "All tests passed."
end program test

subroutine foo
end subroutine

subroutine bar
end subroutine

subroutine test_foo
  call foo
  print *, "foo passed."
end subroutine

subroutine test_bar
  call bar
  print *, "bar passed."
end subroutine