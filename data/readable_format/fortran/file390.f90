module test_mod
  implicit none
  integer :: ii = 0
  save ii
end module test_mod

subroutine foo
  use test_mod
  ii = ii + 1
end subroutine foo

subroutine bar
  use test_mod
  ii = ii + 1
end subroutine bar

program test_program
  use test_mod
  implicit none
  
  ! Test the behavior of `foo` and `bar` retaining the value of `ii` across calls
  call foo()
  print *, 'After first call to foo, ii = ', ii
  
  call bar()
  print *, 'After first call to bar, ii = ', ii
  
  call foo()
  print *, 'After second call to foo, ii = ', ii
  
  call bar()
  print *, 'After second call to bar, ii = ', ii
end program test_program