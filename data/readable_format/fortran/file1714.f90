program MainProgram
    implicit none

    ! Assuming Real8_ from ModKind is a double precision
    integer, parameter :: Real8_ = selected_real_kind(15, 307)
    double precision :: tSimulation = 0.0D0
    integer :: iTimeArray(7) = 0
    double precision :: CurrentTime, EndTime, StartTime, VernalTime
    double precision :: PauseTime
    double precision :: utime
    integer :: iJulianDay, iDay
    integer :: iStep = 1

    integer, parameter :: iYear_ = 1
    integer, parameter :: iMonth_ = 2
    integer, parameter :: iDay_ = 3
    integer, parameter :: iHour_ = 4
    integer, parameter :: iMinute_ = 5
    integer, parameter :: iSecond_ = 6

    ! Example of using the variables
    print *, 'Initial tSimulation:', tSimulation
    print *, 'Initial iTimeArray:', iTimeArray
    print *, 'Constants iYear_, iMonth_, iDay_, iHour_, iMinute_, iSecond_:', &
             iYear_, iMonth_, iDay_, iHour_, iMinute_, iSecond_
    print *, 'iStep:', iStep

    ! You can add additional logic or procedures that manipulate these variables here
end program MainProgram