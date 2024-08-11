program testUp
  implicit none
  
  call TestUpFunction()
  call TestMainLogic()
  
contains

  function Up(string) result(convertedString)
    character(len=*), intent(in) :: string
    character(len=20) :: convertedString
    integer :: i
    
    convertedString = string  ! Initialize with the original string
    do i = 1, len(string)
      if (iachar(string(i:i)) >= iachar('a') .and. iachar(string(i:i)) <= iachar('z')) then
        convertedString(i:i) = achar(iachar(string(i:i)) - (iachar('a') - iachar('A')))
      else
        convertedString(i:i) = string(i:i)
      end if
    end do
  end function Up

  subroutine TestUpFunction()
    if (Up("hello") /= "HELLO") then
      print *, "Up function test failed for hello."
      stop 2
    end if
    if (Up("world") /= "WORLD") then
      print *, "Up function test failed for world."
      stop 2
    end if
    if (Up("TestString") /= "TESTSTRING") then
      print *, "Up function test failed for TestString."
      stop 2
    end if
    print *, "All Up function tests passed."
  end subroutine TestUpFunction

  subroutine TestMainLogic()
    character(len=13) :: testStr
    testStr = Up("AbCdEfGhIjKlM")
    if (testStr == "ABCDEFGHIJKLM") then
      print *, "Main logic test passed."
    else
      print *, "Main logic test failed."
      stop 1
    end if
  end subroutine TestMainLogic

end program testUp