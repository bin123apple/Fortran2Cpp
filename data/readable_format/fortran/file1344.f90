program test_closeunit
  implicit none
  integer :: unitnum
  logical :: opened

  ! Assign a unit number
  unitnum = 10
  ! Open a temporary file
  open(unit=unitnum, file='testfile.txt', status='replace', action='write')
  ! Write something to the file
  write(unitnum,*) 'Testing closeunit subroutine'
  ! Close the file using the subroutine
  call closeunit(unitnum)

  ! Check if the file is closed
  inquire(unit=unitnum, opened=opened)
  if (.not. opened) then
    print *, 'Test passed: File is closed.'
  else
    print *, 'Test failed: File is still open.'
  endif
end program test_closeunit

subroutine closeunit(unitnum)
  integer :: unitnum
  close(unitnum)
end subroutine closeunit