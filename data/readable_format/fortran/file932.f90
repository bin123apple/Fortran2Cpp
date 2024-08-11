! This version is unchanged, provided for context. Unit tests will be a separate program.
program file_example
  implicit none

  integer :: ierror

  open (unit=13, file="test.dat", status="new", action="write", iostat=ierror)
  if (ierror /= 0) then
    print*, "Failed to open test.dat"
    stop
  end if

  write (unit=13, fmt=*) "Hello world!"
  close (unit=13)
end program file_example