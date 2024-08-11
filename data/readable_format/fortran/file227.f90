program test_ppm_tree_boxcost
    implicit none

    ! Declarations for single and double precision tests
    real :: single_precision_result
    double precision :: double_precision_result
    real :: expected_single_precision_result = 1.0
    double precision :: expected_double_precision_result = 1.0d0

    ! Test single precision
    single_precision_result = ppm_tree_boxcost_s(2.0)
    if (abs(single_precision_result - expected_single_precision_result) > 1.0E-6) then
        print *, "Single precision test failed."
    else
        print *, "Single precision test passed."
    endif

    ! Test double precision
    double_precision_result = ppm_tree_boxcost_d(2.0d0)
    if (abs(double_precision_result - expected_double_precision_result) > 1.0E-15) then
        print *, "Double precision test failed."
    else
        print *, "Double precision test passed."
    endif

contains

    ! Function definitions
    function ppm_tree_boxcost_s(x) result(cost)
        real, intent(in) :: x
        real :: cost
        ! Placeholder computation - replace with your actual logic
        cost = 1.0
    end function ppm_tree_boxcost_s

    function ppm_tree_boxcost_d(x) result(cost)
        double precision, intent(in) :: x
        double precision :: cost
        ! Placeholder computation - replace with your actual logic
        cost = 1.0d0
    end function ppm_tree_boxcost_d

end program test_ppm_tree_boxcost