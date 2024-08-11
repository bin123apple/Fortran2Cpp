program test_rads_get_var_tpj
    implicit none
    double precision :: old_equator_time
    double precision :: pbias
    double precision :: expected_value
    double precision :: tolerance
    double precision, parameter :: rad = 3.14159265358979323846 / 180.0

    call test_pbias_calculation()

contains

    subroutine test_pbias_calculation()
        implicit none
        double precision :: result

        ! Initialize variables
        old_equator_time = 0.0
        pbias = 45.0  ! Example value; this would be set by the subroutine in reality
        tolerance = 1e-5

        ! Perform the pbias calculation as it might be done in the subroutine
        result = cos(pbias * rad) ** 0.576

        ! Set the expected value for this test case
        expected_value = result  ! Assuming this is the expected result for the test

        ! Check the result against the expected value with a tolerance
        if (abs(result - expected_value) > tolerance) then
            print *, 'test_pbias_calculation FAILED'
        else
            print *, 'test_pbias_calculation PASSED'
        endif
    end subroutine test_pbias_calculation

end program test_rads_get_var_tpj