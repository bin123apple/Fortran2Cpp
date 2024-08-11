! Define the subroutine
subroutine strippath(fnam2,fnam,path,iflag)
  character(len=80) :: fnam2
  character(len=13) :: fnam
  character(len=80) :: path
  integer :: iflag, i
  
  iflag=0
  
  do i=1, len(fnam2)
    if(fnam2(i:i) .eq. '/') then
      iflag=i
    endif
  end do
  
  if(iflag.gt.0) then
    fnam=fnam2(iflag+1:)
    path=fnam2(1:iflag)
  else
    fnam=fnam2
    path=""
  endif
end subroutine strippath

! Unit tests
program testStripPath
  implicit none
  character(len=80) :: fnam2, path
  character(len=13) :: fnam
  integer :: iflag

  ! Test 1
  fnam2 = "/path/to/the/file.txt"
  call strippath(fnam2,fnam,path,iflag)
  print *, "Test 1 - Filename:", trim(fnam)
  print *, "Test 1 - Path:", trim(path)
  print *, "Test 1 - Position of last '/':", iflag

  ! Test 2
  fnam2 = "file.txt"
  call strippath(fnam2,fnam,path,iflag)
  print *, "Test 2 - Filename:", trim(fnam)
  print *, "Test 2 - Path:", trim(path)
  print *, "Test 2 - Position of last '/':", iflag

  ! Test 3
  fnam2 = "/path/to/multiple/slashes/file.txt"
  call strippath(fnam2,fnam,path,iflag)
  print *, "Test 3 - Filename:", trim(fnam)
  print *, "Test 3 - Path:", trim(path)
  print *, "Test 3 - Position of last '/':", iflag
end program testStripPath