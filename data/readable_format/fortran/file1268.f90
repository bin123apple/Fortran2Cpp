module netcdf_mod
  implicit none
contains
  subroutine open_file(filename)
    character(len=*), intent(in) :: filename
    print *, 'Opening file: ', trim(filename)
  end subroutine open_file

  function get_dimension(dimName) result(dim)
    character(len=*), intent(in) :: dimName
    integer :: dim
    dim = 10  ! Example dimension
    return
  end function get_dimension
end module netcdf_mod

program test_netcdf
  use netcdf_mod
  implicit none
  integer :: dim

  call open_file('example.nc')
  dim = get_dimension('time')
  print *, 'Dimension: ', dim
end program test_netcdf