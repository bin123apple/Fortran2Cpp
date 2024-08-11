module module_myobj

  implicit none

  type :: myobj
  contains
    procedure, nopass :: myfunc
  end type

contains

  integer function myfunc(status)
    integer, optional :: status
    if (present(status)) then
      myfunc = 1
    else
      myfunc = 2
    end if
  end function

end module


program test_myobj

  use :: module_myobj
  implicit none

  integer     :: res = 0
  type(myobj) :: myinstance

  ! Test case 1: Call myfunc without arguments
  res = myinstance%myfunc()
  if (res /= 2) then
    print *, "Test case 1 failed"
    call abort()
  end if

  ! Test case 2: Call myfunc with argument
  res = myinstance%myfunc(1)
  if (res /= 1) then
    print *, "Test case 2 failed"
    call abort()
  end if

  print *, "All tests passed."

end program