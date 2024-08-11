module string_checks
  implicit none
contains
  function isHelloWorld(c) result(res)
    character(len=*), intent(in) :: c
    logical :: res
    res = c == "Hello, world!"
  end function isHelloWorld
end module string_checks

program main
  use string_checks
  implicit none
  logical :: result

  result = isHelloWorld("Hello, world!")
  if (.not. result) call abort()
  
  ! This will not trigger in the main program but is here to illustrate failure
  result = isHelloWorld("Goodbye, world!")
  if (.not. result) call abort()
end program main