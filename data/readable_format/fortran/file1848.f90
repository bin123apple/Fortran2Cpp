program testFoo
  call foo()
end program testFoo

pure subroutine foo()
  error stop "failed"
end subroutine foo