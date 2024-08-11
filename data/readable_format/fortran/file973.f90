module netcdf_utilities
  implicit none
contains
  function openFile(filename) result(status)
    implicit none
    character(len=*), intent(in) :: filename
    integer :: status
    
    ! Mock implementation of opening a file and returning a status code
    ! 0 indicates success, non-zero indicates failure (simplified example)
    if (trim(filename) == 'example.nc') then
      status = 0
    else
      status = -1
    end if
  end function openFile
end module netcdf_utilities

program test_netcdf
  use netcdf_utilities
  implicit none
  
  integer :: status
  
  ! Test openFile function
  print *, "Testing openFile with 'example.nc'"
  status = openFile('example.nc')
  if (status == 0) then
    print *, "Test passed."
  else
    print *, "Test failed."
  end if
  
  print *, "Testing openFile with 'nonexistent.nc'"
  status = openFile('nonexistent.nc')
  if (status /= 0) then
    print *, "Test passed."
  else
    print *, "Test failed."
  end if
end program test_netcdf