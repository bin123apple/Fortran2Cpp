program test_functions
    implicit none

    interface
        real function egs_secnds(t0)
            real, intent(in) :: t0
        end function egs_secnds

        real function egs_tot_time(flag)
            integer, intent(in) :: flag
        end function egs_tot_time
    end interface

    real :: result
    integer :: flag

    ! Test egs_secnds
    result = egs_secnds(0.0)
    if (result == 0.0) then
        print *, "Test for egs_secnds passed."
    else
        print *, "Test for egs_secnds failed."
    endif

    ! Test egs_tot_time
    flag = 0
    result = egs_tot_time(flag)
    if (result == 0.0) then
        print *, "Test for egs_tot_time passed."
    else
        print *, "Test for egs_tot_time failed."
    endif

end program test_functions

! Original functions for completeness
real function egs_secnds(t0)
    real, intent(in) :: t0
    egs_secnds = 0
end function egs_secnds

real function egs_tot_time(flag)
    integer, intent(in) :: flag
    egs_tot_time = 0
end function egs_tot_time