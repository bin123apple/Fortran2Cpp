module constants
    implicit none
    integer, parameter :: RLEN = selected_real_kind(15, 307)
    real(kind=RLEN), parameter :: SEC_PER_DAY = 86400.0_RLEN
end module constants

module time_module
    use constants, only: RLEN
    implicit none
    real(kind=RLEN) :: timestep = 43200.0_RLEN
end module time_module

module delta_module
    use constants, only: RLEN, SEC_PER_DAY
    use time_module, only: timestep
    implicit none
contains
    function GetDelta() result(Delta)
       real(kind=RLEN) :: Delta
       Delta = timestep / SEC_PER_DAY
    end function GetDelta
end module delta_module

program testGetDelta
    use constants, only: RLEN
    use delta_module, only: GetDelta
    implicit none
    real(kind=RLEN) :: result

    result = GetDelta()
    print *, "Expected Delta: ", 0.5_RLEN
    print *, "Computed Delta: ", result

    if (abs(result - 0.5_RLEN) < 1.0e-7_RLEN) then
        print *, "Test Passed."
    else
        print *, "Test Failed."
    end if
end program testGetDelta