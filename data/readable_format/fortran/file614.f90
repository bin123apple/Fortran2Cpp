module mpoint
  implicit none
  type :: mytype
    integer :: i
  end type mytype
contains
  function get(a) result(b)
    type(mytype), target :: a
    type(mytype), pointer :: b
    b => a
  end function get

  function get2(a) result(b)
    type(mytype), target :: a
    type(mytype), pointer :: b
    b => a
  end function get2
end module mpoint

program test_mpoint
  use mpoint
  implicit none
  type(mytype), target :: x
  type(mytype), pointer :: y

  ! Test 1 for get function
  x = mytype(42)
  y => get(x)
  if (y%i /= 42) then
    print *, "Test 1 failed."
    stop 1
  else
    print *, "Test 1 passed."
  end if

  ! Test 2 for get2 function
  x = mytype(112)
  y => get2(x)
  if (y%i /= 112) then
    print *, "Test 2 failed."
    stop 2
  else
    print *, "Test 2 passed."
  end if
end program test_mpoint