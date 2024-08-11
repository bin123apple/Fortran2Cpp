program test_power_multiply
    real :: x
    real, parameter :: expected = 0.625
    x = 2.0 ** -3 * 5
    if (abs(x - expected) < 1.0E-5) then
        print *, "Test passed: x = ", x
    else
        print *, "Test failed: x = ", x, " expected: ", expected
    endif
end program test_power_multiply