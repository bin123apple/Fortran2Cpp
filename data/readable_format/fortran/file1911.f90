program write_a_1
  implicit none
  character(len=25) :: s

  ! Test 1
  write(s, '(A11)') "hello world"
  if (s /= "hello world") stop 1

  ! Test 2
  write(s, '(A2)') "hello world"
  if (s /= "he") stop 2

  ! Test 3
  write(s, '(A18)') "hello world"
  if (trim(adjustl(s)) /= "hello world") stop 3

  print *, "Fortran Program Passed All Tests"
end program write_a_1