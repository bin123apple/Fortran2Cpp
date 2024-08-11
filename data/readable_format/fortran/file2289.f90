program test_clock
    implicit none
    real :: start_time, stop_time, elapsed_time, count_rate
    integer :: clock_start, clock_end, clock_rate

    ! Initialize the clock
    call system_clock(count_rate=count_rate)
    
    ! Start the clock
    call system_clock(clock_start, clock_rate)
    start_time = real(clock_start) / real(clock_rate)
    
    ! Simulate some work with a pause (e.g., sleep for 2 seconds)
    call sleep(2)
    
    ! Stop the clock
    call system_clock(clock_end)
    stop_time = real(clock_end) / real(clock_rate)
    
    ! Calculate elapsed time
    elapsed_time = stop_time - start_time
    
    ! Print the elapsed time to check if it is approximately 2 seconds
    print *, 'Elapsed time: ', elapsed_time, ' seconds'

contains
    ! Helper subroutine to simulate work by sleeping
    subroutine sleep(seconds)
        integer, intent(in) :: seconds
        integer :: count_rate, start, finish, elapsed
        call system_clock(start, count_rate)
        elapsed = 0
        do while (elapsed < seconds * count_rate)
            call system_clock(finish)
            elapsed = finish - start
        end do
    end subroutine sleep
end program test_clock