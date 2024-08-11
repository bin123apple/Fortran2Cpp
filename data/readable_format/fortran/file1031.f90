program test_gsw_specvol_derivatives
    implicit none

    ! Test inputs
    real :: sa_test, ct_test, p_test
    real :: v_sa, v_h
    integer :: iflag_test

    ! Initialize some test values
    sa_test = 35.0
    ct_test = 10.0
    p_test = 1000.0
    iflag_test = 3

    ! Case 1: Test with both v_sa and v_h
    call gsw_specvol_first_derivatives_wrt_enthalpy(sa_test, ct_test, p_test, v_sa, v_h, iflag_test)
    print *, "Case 1: v_sa =", v_sa, ", v_h =", v_h

    ! Add more cases as needed to thoroughly test your subroutine

contains

    subroutine gsw_specvol_first_derivatives_wrt_enthalpy(sa, ct, p, v_sa, v_h, iflag)
        implicit none
        real, intent(in) :: sa, ct, p
        integer, intent(in), optional :: iflag
        real, intent(out), optional :: v_sa, v_h

        real :: h_ct, h_sa, rec_h_ct, vct_ct, vct_sa
        integer :: i
        logical, dimension(2) :: flags = [.true., .true.]

        if (present(iflag)) then
            do i = 1, 2
                flags(i) = ibits(iflag, i-1, 1) /= 0
            end do
        endif

        ! Placeholder implementations
        call gsw_specvol_first_derivatives(sa,ct,p,vct_sa,vct_ct)
        call gsw_enthalpy_first_derivatives(sa,ct,p,h_sa,h_ct)

        rec_h_ct = 1.0 / h_ct

        if (present(v_sa) .and. flags(1)) v_sa = vct_sa - (vct_ct * h_sa) * rec_h_ct
        if (present(v_h) .and. flags(2)) v_h = vct_ct * rec_h_ct
    end subroutine gsw_specvol_first_derivatives_wrt_enthalpy

    ! Placeholder for actual gsw_specvol_first_derivatives implementation
    subroutine gsw_specvol_first_derivatives(sa, ct, p, vct_sa, vct_ct)
        implicit none
        real, intent(in) :: sa, ct, p
        real, intent(out) :: vct_sa, vct_ct
        ! Placeholder calculations
        vct_sa = 0.1
        vct_ct = 0.2
    end subroutine gsw_specvol_first_derivatives

    ! Placeholder for actual gsw_enthalpy_first_derivatives implementation
    subroutine gsw_enthalpy_first_derivatives(sa, ct, p, h_sa, h_ct)
        implicit none
        real, intent(in) :: sa, ct, p
        real, intent(out) :: h_sa, h_ct
        ! Placeholder calculations
        h_sa = 0.3
        h_ct = 0.4
    end subroutine gsw_enthalpy_first_derivatives

end program test_gsw_specvol_derivatives