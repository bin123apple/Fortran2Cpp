program read_binary
    implicit none
    integer :: iounit, ios
    real :: num

    open(newunit=iounit, file='data.bin', status='old', action='read', form='unformatted', access='sequential', iostat=ios)
    if (ios /= 0) then
        print *, 'Cannot open file!'
        stop
    end if

    read(iounit, iostat=ios) num
    if (ios /= 0) then
        print *, 'Read error!'
        stop
    else
        print *, 'Read number: ', num
    end if

    close(iounit)
end program read_binary