program test_namelist
    real :: x
    namelist /mynml/ x
    x = 1
    ! Test if x is initialized correctly
    if (x == 1) then
        print *, "Test Passed: x is initialized to 1"
    else
        print *, "Test Failed: x is not initialized to 1"
    end if
end program test_namelist