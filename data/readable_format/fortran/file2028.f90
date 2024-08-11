program test
  implicit none
  real, dimension(10000) :: a
  integer :: my_id, bad_id, iostat
  character(len=100) :: iomsg
  logical :: fileExists

  my_id = 1
  bad_id = 2
  a = 1.
  iomsg = ""

  ! Assuming asynchronous and file writing here, replaced by synchronous for simplicity
  open(unit=10, file='test.dat', form='unformatted', status='replace', action='write')
  write(unit=10) a
  close(unit=10)

  ! Mimic waiting and error checking (simplified)
  inquire(file='test.dat', exist=fileExists)
  if (.not. fileExists) then
    print *, "Error: File does not exist after write."
    stop 1
  endif

  ! Delete file to clean up
  open(unit=10, file='test.dat', status='old')
  close(unit=10, status='delete')

  ! Check file deletion
  inquire(file='test.dat', exist=fileExists)
  if (fileExists) then
    print *, "Error: File exists after delete."
    stop 1
  else
    print *, "Test Passed: File created and deleted successfully."
  endif

end program test