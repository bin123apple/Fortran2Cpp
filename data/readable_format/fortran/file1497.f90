program testFileOperations
  implicit none
  integer :: iounit, ios
  character(len=255) :: filename
  logical :: fileExists

  filename = 'tmpfile_test'
  
  ! Create and write to the file
  open(newunit=iounit, file=filename, status='replace', action='write')
  write(iounit,*) 'Test'
  close(iounit)

  ! Check if the file was created
  inquire(file=filename, exist=fileExists)
  if (.not. fileExists) then
    print *, 'Test Failed: File was not created.'
  else
    print *, 'File creation test passed.'
  endif

  ! Delete the file
  open(newunit=iounit, file=filename, status='old', action='read')
  close(iounit, status='delete')

  ! Check if the file was deleted
  inquire(file=filename, exist=fileExists)
  if (fileExists) then
    print *, 'Test Failed: File was not deleted.'
  else
    print *, 'File deletion test passed.'
  endif
  
end program testFileOperations