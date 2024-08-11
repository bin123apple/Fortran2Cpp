program addAttributeManually
    implicit none
    character(len=255) :: line
    integer :: iostat
    character(len=*), parameter :: filename = "test.xml"
    character(len=*), parameter :: tmpFilename = "test_tmp.xml"

    open(unit=10, file=filename, status='old', action='read', iostat=iostat)
    if (iostat /= 0) then
        print *, "Error opening file: ", filename
        stop
    end if

    open(unit=20, file=tmpFilename, status='replace', action='write', iostat=iostat)
    if (iostat /= 0) then
        print *, "Error creating temporary file: ", tmpFilename
        stop
    end if

    read(10, '(A)', iostat=iostat) line
    if (iostat /= 0) then
        print *, "Error reading from file: ", filename
        stop
    end if

    ! WARNING: This is a naive approach and might not work for your XML structure.
    ! This example just appends a pseudo attribute at the end of the first line.
    line = trim(line) // ' att="value"'

    write(20, '(A)') line

    do while (iostat == 0)
        read(10, '(A)', iostat=iostat) line
        if (iostat == 0) then
            write(20, '(A)') line
        end if
    end do

    close(10)
    close(20)

    ! Replace the original file with the modified one
    call execute_command_line("mv " // trim(tmpFilename) // " " // trim(filename))
end program addAttributeManually