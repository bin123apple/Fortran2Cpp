! Compile with: gfortran -o fortran_test fortran_code.f90
! Run with: ./fortran_test

module kinds
    implicit none
    integer, parameter :: r8 = selected_real_kind(15, 307)
end module kinds

module freezing_functions
    use kinds, only: r8
    implicit none
    ! Example coefficients and constants for demonstration
    real(r8), parameter :: gsw_sso = 35.0_r8
    real(r8), parameter :: c0 = 0.0_r8, c1 = 1.0_r8, c2 = 2.0_r8, c3 = 3.0_r8, c4 = 4.0_r8
    real(r8), parameter :: c5 = 5.0_r8, c6 = 6.0_r8, c7 = 7.0_r8, c8 = 8.0_r8, c9 = 9.0_r8
    real(r8), parameter :: c10 = 10.0_r8, c11 = 11.0_r8, c12 = 12.0_r8, c13 = 13.0_r8
    real(r8), parameter :: c14 = 14.0_r8, c15 = 15.0_r8, c16 = 16.0_r8, c17 = 17.0_r8
    real(r8), parameter :: c18 = 18.0_r8, c19 = 19.0_r8, c20 = 20.0_r8, c21 = 21.0_r8
    real(r8), parameter :: c22 = 22.0_r8
    real(r8), parameter :: a = 1.0_r8, b = 2.0_r8

contains

    real(r8) function gsw_ct_freezing_poly(sa, p, saturation_fraction)
        real(r8), intent(in) :: sa, p, saturation_fraction
        real(r8) :: sa_r, p_r, x

        sa_r = sa*1e-2_r8
        x = sqrt(sa_r)
        p_r = p*1e-4_r8

        gsw_ct_freezing_poly = c0 + sa_r*(c1 + x*(c2 + x*(c3 + x*(c4 + x*(c5 + c6*x))))) &
            + p_r*(c7 + p_r*(c8 + c9*p_r)) + sa_r*p_r*(c10 + p_r*(c12 &
            + p_r*(c15 + c21*sa_r)) + sa_r*(c13 + c17*p_r + c19*sa_r) &
            + x*(c11 + p_r*(c14 + c18*p_r) + sa_r*(c16 + c20*p_r + c22*sa_r)))

        gsw_ct_freezing_poly = gsw_ct_freezing_poly - saturation_fraction* &
            (1e-3_r8)*(2.4_r8 - a*sa)*(1.0_r8 + b*(1.0_r8 - sa/gsw_sso))
    end function gsw_ct_freezing_poly

end module freezing_functions

program test_gsw_ct_freezing
    use kinds, only: r8
    use freezing_functions, only: gsw_ct_freezing_poly
    implicit none
    real(r8) :: result

    result = gsw_ct_freezing_poly(35.0_r8, 100.0_r8, 0.5_r8)

    print *, "Result: ", result

end program test_gsw_ct_freezing