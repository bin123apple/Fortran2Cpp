program test_gsw_ct_freezing
    use iso_fortran_env, only: real64
    implicit none
    real(real64) :: sa_test, p_test, saturation_fraction_test
    real(real64) :: expected, result

    ! Example test case
    sa_test = 35.0_real64
    p_test = 100.0_real64
    saturation_fraction_test = 1.0_real64
    expected = -2.5_real64  ! Hypothetical expected value for demonstration

    result = gsw_ct_freezing_exact(sa_test, p_test, saturation_fraction_test)
    print *, "Test 1: ", result, "Expected: ", expected

contains

    ! Placeholder for the actual gsw_t_freezing_exact function
    real(real64) function gsw_t_freezing_exact(sa, p, saturation_fraction)
        real(real64), intent(in) :: sa, p, saturation_fraction
        gsw_t_freezing_exact = -2.0_real64  ! Placeholder return value
    end function gsw_t_freezing_exact

    ! Placeholder for the actual gsw_ct_from_t function
    real(real64) function gsw_ct_from_t(sa, t, p)
        real(real64), intent(in) :: sa, t, p
        gsw_ct_from_t = -2.5_real64  ! Placeholder return value
    end function gsw_ct_from_t

    ! Function to compute Conservative Temperature at which seawater freezes
    real(real64) function gsw_ct_freezing_exact(sa, p, saturation_fraction)
        real(real64), intent(in) :: sa, p, saturation_fraction
        real(real64) :: t_freezing

        t_freezing = gsw_t_freezing_exact(sa, p, saturation_fraction)
        gsw_ct_freezing_exact = gsw_ct_from_t(sa, t_freezing, p)
    end function gsw_ct_freezing_exact

end program test_gsw_ct_freezing