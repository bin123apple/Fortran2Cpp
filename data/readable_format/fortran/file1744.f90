! Combined file with both the writestadiv subroutine and a test program
program testWritestadiv
    implicit none

    ! Variables for test
    integer :: istep, j, icutb, l
    real*8 :: ttime, time, dtime

    ! Open a file with unit number 8 for writing
    open(8, file='output_fortran.txt', status='replace')

    ! Sample test values for the subroutine
    istep = 1
    j = 2
    icutb = 3
    l = 4
    ttime = 5.0
    time = 6.0
    dtime = 1.0

    ! Call the subroutine with the test values
    call writestadiv(istep, j, icutb, l, ttime, time, dtime)

    ! Close the file
    close(8)

contains

    ! The writestadiv subroutine definition
    subroutine writestadiv(istep, j, icutb, l, ttime, time, dtime)
        implicit none

        ! Subroutine arguments
        integer :: istep, j, icutb, l
        real*8 :: ttime, time, dtime

        ! Write to file unit 8 with the specified format
        write(8,100) istep, j, icutb + 1, l, ttime + time - dtime, time - dtime, dtime
        flush(8)

        ! Format statement
    100 format(1x,i5,1x,i10,1x,i5,'U',1x,i4,3(1x,e13.6))

    end subroutine writestadiv

end program testWritestadiv