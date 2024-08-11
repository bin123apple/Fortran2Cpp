program test_gsw_alpha_wrt_t_ice
    implicit none
    ! Define kinds for precision, assuming r8 is double precision
    integer, parameter :: dp = selected_real_kind(15, 307)
    real(dp) :: result, t, p

    ! Test case 1
    t = 263.15_dp  ! Kelvin
    p = 10.0_dp    ! Decibars
    result = gsw_alpha_wrt_t_ice(t, p)
    print *, "Test case 1: T=", t, "P=", p, "Alpha=", result

    ! Add more test cases as needed

contains

    function gsw_gibbs_ice(n1, n2, t, p) result(value)
        integer, intent(in) :: n1, n2
        real(dp), intent(in) :: t, p
        real(dp) :: value
        ! Dummy implementation - replace with the actual function's logic
        value = t * p * 0.01_dp
    end function gsw_gibbs_ice

    function gsw_alpha_wrt_t_ice(t, p) result(alpha)
        real(dp), intent(in) :: t, p
        real(dp) :: alpha
        alpha = gsw_gibbs_ice(1, 1, t, p) / gsw_gibbs_ice(0, 1, t, p)
    end function gsw_alpha_wrt_t_ice

end program test_gsw_alpha_wrt_t_ice