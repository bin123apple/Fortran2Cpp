program test_main
  implicit none
  type t
     character(len=2) :: x
  end type t
  type(t) :: a
  character(len=3) :: b
  character(len=10) :: line

  ! Test 1
  a%x = 'a'
  write(unit=line,fmt='(A,A)') trim(a%x), "X"
  if (line /= 'aX        ') then
     print *, "Test 1 Failed"
  else
     print *, "Test 1 Passed"
  end if

  ! Test 2
  b = 'ab'
  write(unit=line,fmt='(A,A)') trim(b), "Y"
  if (line /= 'abY       ') then
     print *, "Test 2 Failed"
  else
     print *, "Test 2 Passed"
  end if

end program test_main