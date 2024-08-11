program test_timestamp
    implicit none

    ! Declaration of variables for test cases
    integer :: d, m, y, h, n, s
    character(len=20) :: ampm
    character(len=60) :: formatted_time

    ! Example test case 1: Noon
    d = 15; m = 7; y = 2023; h = 12; n = 0; s = 0
    call timestamp(d, m, y, h, n, s, ampm, formatted_time)
    print *, 'Test Case Noon:', formatted_time

    ! Example test case 2: Midnight
    d = 16; m = 7; y = 2023; h = 0; n = 0; s = 0
    call timestamp(d, m, y, h, n, s, ampm, formatted_time)
    print *, 'Test Case Midnight:', formatted_time

    ! Add additional test cases as needed

contains

    subroutine timestamp(d, m, y, h, n, s, ampm, formatted_time)
        implicit none
        integer, intent(in) :: d, m, y, h, n, s
        character(len=20), intent(out) :: ampm
        character(len=60), intent(out) :: formatted_time
        character(len=9), dimension(12) :: month = [ &
             'January  ', 'February ', 'March    ', 'April    ', &
             'May      ', 'June     ', 'July     ', 'August   ', &
             'September', 'October  ', 'November ', 'December ' ]
        integer :: hh

        if (h >= 12) then
            if (h > 12) then
                hh = h - 12
            else
                hh = h
            end if
            if (h == 12 .and. n == 0 .and. s == 0) then
                ampm = 'Noon'
            else
                ampm = 'PM'
            end if
        else
            hh = h
            if (h == 0) then
                hh = 12
                ampm = 'Midnight'
            else
                ampm = 'AM'
            end if
        end if

        write(formatted_time, '(I2, " ", A, " ", I4, " ", I2, ":", I2.2, ":", I2.2, " ", A)') &
             d, trim(month(m)), y, hh, n, s, trim(ampm)

    end subroutine timestamp

end program test_timestamp