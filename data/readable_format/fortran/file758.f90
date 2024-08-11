! error.f90
subroutine error(function_name, message, value, level)
    implicit none
    character(len=*), intent(in) :: function_name
    character(len=*), intent(in) :: message
    real(8), intent(in) :: value
    integer, intent(in) :: level

    if ((level .lt. 1) .or. (level .gt. 3)) then
        print *, '*** Error in Subroutine error:'
        print *, '*** Message: Wrong Errorlevel'
        print *, '*** Related Value: ', level
    end if

    if (level .eq. 1) then
        print *, '*** Warning in Subroutine ', trim(function_name), ':'
    elseif (level .eq. 2) then
        print *, '*** Error in Subroutine ', trim(function_name), ':'
    elseif (level .eq. 3) then
        print *, '*** Fatal Error in Subroutine ', trim(function_name), ':'
    end if
    print *, '*** Message: ', trim(message)
    print *, '*** Related Value: ', value

    if (level .ge. 3) then
        print *, '*** Program stopped.'
        stop 137
    end if
end subroutine error


! test_error.f90
program test_error
    implicit none

    call error('testFunc1', 'This is a warning message.', 1.0d0, 1)
    call error('testFunc2', 'This is an error message.', 2.0d0, 2)
    call error('testFunc3', 'This is a fatal error message.', 3.0d0, 3)
    call error('testFunc4', 'This should complain about error level.', 4.0d0, 0)
end program test_error