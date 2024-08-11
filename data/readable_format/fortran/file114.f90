! This program demonstrates creating an XML file with specific contents
! and includes a basic "unit test" by reading back the file and checking for expected strings.
program testXML
    implicit none
    character(len=:), allocatable :: xmlContent
    integer :: ioStatus

    ! Create XML file
    call createXML()

    ! Basic check of the XML file content
    call checkXML()

contains

    subroutine createXML()
        ! Open file
        open(unit=10, file='test.xml', status='replace', action='write')

        ! Write contents similar to the original XML functionality
        write(10, '(a)') '<?xml version="1.0" encoding="UTF-8"?>'
        write(10, '(a)') '<!DOCTYPE html>'
        ! Using a comment to simulate parameter entity
        write(10, '(a)') '<!-- Parameter Entity: copy "http://www.uszla.me.uk/entities" -->'
        write(10, '(a)') '<html>'

        ! Close the tag and file for simplicity
        write(10, '(a)') '</html>'
        close(10)
    end subroutine createXML

    subroutine checkXML()
        character(len=1024) :: line

        ! Open and read the file
        open(unit=11, file='test.xml', status='old', action='read')
        
        ! Attempt to read the lines and check for specific content
        do
            read(11, '(A)', iostat=ioStatus) line
            if (ioStatus /= 0) exit
            if (index(line, '<!DOCTYPE html>') /= 0) then
                print *, "Found DOCTYPE declaration."
            end if
            if (index(line, 'Parameter Entity:') /= 0) then
                print *, "Found Parameter Entity comment."
            end if
            if (index(line, '<html>') /= 0) then
                print *, "Found opening <html> element."
            end if
            if (index(line, '</html>') /= 0) then
                print *, "Found closing </html> element."
            end if
        end do
        close(11)

        ! Indicate test completion
        print *, "Basic XML content check completed."
    end subroutine checkXML

end program testXML