! Test for Fortran program
program testFortran
  implicit none
  integer :: iounit
  character(len=255) :: line

  ! Attempt to open file, write to it, then close it
  open(unit=iounit, file='testfile', status='new', form='formatted', action='write')
  write(iounit,*) 'Test'
  close(iounit)

  ! Reopen file for reading and verify content
  open(unit=iounit, file='testfile', status='old', form='formatted', action='read')
  read(iounit,*) line
  if (line == 'Test') then
    print *, "Read/Write Test Passed"
  else
    print *, "Read/Write Test Failed"
  endif
  close(iounit)

  ! Clean up
  call execute_command_line("rm testfile")

end program testFortran