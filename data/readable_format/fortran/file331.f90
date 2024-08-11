program test
  implicit none
  integer :: iounit, ios
  character(len=10) :: a
  logical :: file_exists_before, file_exists_after

  ! Function to check if a file exists before the operation
  inquire(file='tmpfile', exist=file_exists_before)

  ! Your original program logic here (simplified)
  open(newunit=iounit, file='tmpfile', status='replace', action='write')
  write(iounit,*) 'Test'
  close(iounit)

  ! Check if file exists after creation
  inquire(file='tmpfile', exist=file_exists_after)

  ! Print test result for creation
  if (file_exists_before) then
    print *, 'Test failed: File was not supposed to exist before.'
  else if (.not. file_exists_before .and. file_exists_after) then
    print *, 'File created successfully - Test passed.'
  else
    print *, 'Test failed: File creation status uncertain.'
  end if

  ! Attempt to delete the file using execute_command_line
  call execute_command_line('rm tmpfile')

  ! Check again to ensure file was deleted
  inquire(file='tmpfile', exist=file_exists_after)
  if (.not. file_exists_after) then
    print *, 'File deleted successfully - Test passed.'
  else
    print *, 'Test failed: File was not deleted.'
  end if

end program test