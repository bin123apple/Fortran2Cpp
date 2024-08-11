program interpolation_tests
    implicit none
    ! Test variables
    real :: x1, y1, x2, y2, xi, expected_yi, yi
    logical :: test_passed

    ! Define test cases for linear interpolation
    x1 = 0.0
    y1 = 0.0
    x2 = 10.0
    y2 = 10.0
    xi = 5.0
    expected_yi = 5.0  ! Expected result for linear interpolation

    ! Perform the linear interpolation
    yi = linear_interpolation(x1, y1, x2, y2, xi)

    ! Check if the test passed
    test_passed = (abs(yi - expected_yi) < 0.0001)

    if (test_passed) then
        print *, "Test passed: Linear interpolation is correct."
    else
        print *, "Test failed: Linear interpolation is incorrect."
    end if

contains

    ! Linear interpolation function
    function linear_interpolation(x1, y1, x2, y2, xi) result(yi)
        real, intent(in) :: x1, y1, x2, y2, xi
        real :: yi

        yi = y1 + (xi - x1) * (y2 - y1) / (x2 - x1)
    end function linear_interpolation

end program interpolation_tests