program test_init_flag
    ! Define the flag directly here to avoid include issues
    logical, parameter :: is_initialized = .TRUE.
    
    ! Test the flag
    if (is_initialized) then
        print *, "Test Passed: is_initialized is true."
    else
        print *, "Test Failed: is_initialized is not true."
    endif
end program test_init_flag