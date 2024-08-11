module myTypes
  type :: t
    ! Define the structure of 't' here.
    ! For the demonstration, we'll add a dummy variable.
    integer :: dummy
  end type t
end module myTypes

subroutine s()
  use myTypes
  type(t) :: myVar
  ! Demonstrating setting a value and printing
  myVar%dummy = 10
  print *, 'Test passed. Value of dummy: ', myVar%dummy
end subroutine s

program main
  call s()
end program main