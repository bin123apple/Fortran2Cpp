module my_functions
  implicit none
contains
  function foo(i) result(s)
    integer, intent(in) :: i
    character(len=4) :: s
    if (i < 0) then
       s = "1234"
    else
       s = "abcd"
    end if
  end function foo

  function bar(i) result(s)
    integer, intent(in) :: i
    character(len=4) :: s
    if (i < 0) then
      s = "4567"
    else
      s = foo(i)
    end if
  end function bar
end module my_functions

program test
  use my_functions
  implicit none
  character(len=4) :: result

  ! Test foo function
  result = foo(1)
  if (result == "abcd") then
    print *, "foo(1) test passed."
  else
    print *, "foo(1) test failed."
  end if

  ! Test bar function
  result = bar(-1)
  if (result == "4567") then
    print *, "bar(-1) test passed."
  else
    print *, "bar(-1) test failed."
  end if
end program test