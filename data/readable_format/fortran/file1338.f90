module m
  implicit none

  type :: t
    procedure(abc), pointer, nopass :: ptr
  end type t

contains

  function abc(arg) result(res)
    character(len=5), pointer :: res
    character(len=5), target :: arg
    res => arg
  end function abc

end module m

program main
  use m
  implicit none

  type(t) :: x
  character(len=5) :: str = 'abcde'
  character(len=5), pointer :: strptr

  ! Set the procedure pointer
  x%ptr => abc

  ! Test functionality
  strptr => x%ptr(str)
  if (strptr /= 'abcde') then
    print *, 'Test 1 Failed'
  else
    print *, 'Test 1 Passed'
  endif

  str = 'fghij'
  if (strptr /= 'fghij') then
    print *, 'Test 2 Failed'
  else
    print *, 'Test 2 Passed'
  endif

end program main