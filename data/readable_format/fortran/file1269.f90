program testXML
  implicit none
  character(len=255) :: line
  character(len=*), parameter :: filename = 'test.xml'
  integer :: iounit, ios

  open(newunit=iounit, file=filename, status='old', action='read', iostat=ios)
  if (ios /= 0) then
    print *, "Failed to open file: ", filename
    stop
  end if

  do
    read(iounit, '(A)', iostat=ios) line
    if (ios /= 0) exit
    print *, "Read line: ", trim(line)
  end do

  close(iounit)
  print *, "File read successfully."
end program testXML