program test_netcdf
    implicit none
    ! Variable declaration
    integer :: NC_MAX_NAME
    character(len=256) :: filename

    ! Assigning a value to NC_MAX_NAME
    NC_MAX_NAME = 256
    filename = 'example.nc'

    ! Calling the subroutine
    call openFile(filename)

contains

    ! Subroutine to open a file
    subroutine openFile(filename)
        character(len=*), intent(in) :: filename
        ! Open file logic here (dummy for demonstration)
        print *, 'File opened: ', trim(filename)
    end subroutine openFile

end program test_netcdf