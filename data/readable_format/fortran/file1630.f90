subroutine foo(i)
  implicit none
  integer, intent(in) :: i
  character(len=:), allocatable :: s
  
  s = 'Hello'
  print *, 'Testing with i = ', i
  print *, 'Expected length of s: 5'
  print *, 'Actual length of s: ', len(s)
  print *, 'Contents of s: ', s
end subroutine foo

program test_foo_program
  implicit none
  call foo(10)
end program test_foo_program