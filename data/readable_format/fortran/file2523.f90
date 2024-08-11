program test_plugin_clock
implicit none

! Main program to test plugin_clock
call plugin_clock

print *, 'plugin_clock subroutine executed successfully.'

contains

    subroutine plugin_clock()
    ! This subroutine does nothing for now

    end subroutine plugin_clock

end program test_plugin_clock