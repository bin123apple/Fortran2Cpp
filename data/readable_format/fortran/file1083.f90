program test_main
  implicit none

  type mytype
    integer :: a, b, c
  end type mytype

  type(mytype) :: myvar

  myvar%a = 1
  myvar%b = 2
  myvar%c = 3

  if (myvar%a == 1) then
    print *, "Test A Passed"
  else
    print *, "Test A Failed"
  end if

  if (myvar%b == 2) then
    print *, "Test B Passed"
  else
    print *, "Test B Failed"
  end if

  if (myvar%c == 3) then
    print *, "Test C Passed"
  else
    print *, "Test C Failed"
  end if

end program test_main