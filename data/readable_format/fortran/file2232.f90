program test_main
  implicit none

  type xyz
     integer :: x = 123
  end type xyz

  type (xyz) :: a
  type (xyz) b

  ! Test 1: Check if a%x is initialized to 123
  if (a%x /= 123) then
     print *, "Test 1 Failed: a%x is not 123"
     stop 1
  else
     print *, "Test 1 Passed"
  end if

  ! Test 2: Check if b%x is initialized to 123
  if (b%x /= 123) then
     print *, "Test 2 Failed: b%x is not 123"
     stop 1
  else
     print *, "Test 2 Passed"
  end if

  print *, "All tests passed."
end program test_main