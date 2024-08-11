program test_param
    implicit none
    real, parameter :: x = 4, y = 5
    real, parameter :: t = 2
    real :: v1, v2
    v1 = x / t
    v2 = y / t

    ! Check the expected values
    if (abs(v1 - 2.0) > 1.0e-6) then
        print *, "Test failed for v1"
        stop 1
    endif

    if (abs(v2 - 2.5) > 1.0e-6) then
        print *, "Test failed for v2"
        stop 1
    endif

    print *, "All tests passed"
end program test_param