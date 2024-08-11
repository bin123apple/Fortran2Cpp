module m

  type t
  contains
    procedure, nopass :: testsub
    procedure, nopass :: testfun
  end type t

contains

  subroutine testsub()
    print *, "t's test"
  end subroutine testsub

  integer function testfun()
    testfun = 1
  end function testfun

end module m

program test_program
  use m
  type(t) :: x

  call x%testsub()
  print *, x%testfun()

  ! The following is a simple "test" segment within the same program.
  if (x%testfun() == 1) then
    print *, "testfun passed"
  else
    print *, "testfun failed"
  end if
end program test_program