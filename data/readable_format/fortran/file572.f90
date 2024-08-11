program test_brick_tee
    use brick_tee
    implicit none

    ! Define kind parameter for double precision
    integer, parameter :: DP = selected_real_kind(15, 307)
    real(DP) :: thermal
    real(DP) :: deltaH = 10.0_DP
    real(DP) :: thermal_previous = 100.0_DP
    real(DP) :: thermal_current
    real(DP) :: expected_thermal_current
    real(DP) :: expected_thermal_previous
    
    ! Initialize the brick_tee
    call init_brick_tee(1.0_DP, 0.5_DP, 2.0_DP, 4.0_DP, 100.0_DP, thermal)
    
    ! Test brick_tee_step_forward
    call brick_tee_step_forward(deltaH, thermal_previous, thermal_current)
    expected_thermal_current = thermal_previous + deltaH * 0.5_DP / (1.0_DP * 2.0_DP * 2.0_DP * 4.0_DP)
    if (abs(thermal_current - expected_thermal_current) < 1e-6_DP) then
        print *, "brick_tee_step_forward test passed."
    else
        print *, "brick_tee_step_forward test failed."
    end if
    
    ! Test brick_tee_step_backward
    call brick_tee_step_backward(deltaH, thermal_current, thermal_previous)
    expected_thermal_previous = thermal_current - deltaH * 0.5_DP / (1.0_DP * 2.0_DP * 2.0_DP * 4.0_DP)
    if (abs(thermal_previous - expected_thermal_previous) < 1e-6_DP) then
        print *, "brick_tee_step_backward test passed."
    else
        print *, "brick_tee_step_backward test failed."
    end if

end program test_brick_tee

! Include the brick_tee module code here or in a separate file
module brick_tee
    implicit none
    ! Assumed DP definition from your environment
    integer, parameter :: DP = selected_real_kind(15, 307)
    private

    real(DP) :: c, a, rho_te, sa, TE_0
    real(DP) :: TE       

    public :: brick_tee_step_forward, brick_tee_step_backward, init_brick_tee

contains

    subroutine init_brick_tee(h_capacity, expansion_coeff, density0, ocsa, Initial_TE, thermal)
        real(DP), intent(IN) :: h_capacity
        real(DP), intent(IN) :: expansion_coeff
        real(DP), intent(IN) :: density0
        real(DP), intent(IN) :: ocsa
        real(DP), intent(IN) :: Initial_TE
        real(DP), intent(OUT) :: thermal
        
        c = h_capacity
        a = expansion_coeff
        rho_te = density0
        sa = ocsa
        TE_0 = Initial_TE

        thermal = TE_0
        TE = thermal
    end subroutine init_brick_tee

    subroutine brick_tee_step_forward(deltaH, thermal_previous, thermal_current)
        real(DP), intent(IN) :: deltaH
        real(DP), intent(IN) :: thermal_previous
        real(DP), intent(OUT) :: thermal_current

        thermal_current = thermal_previous + deltaH * a / (c * rho_te * rho_te * sa)
        TE = thermal_current
    end subroutine brick_tee_step_forward

    subroutine brick_tee_step_backward(deltaH, thermal_current, thermal_previous)
        real(DP), intent(IN) :: deltaH
        real(DP), intent(IN) :: thermal_current
        real(DP), intent(OUT) :: thermal_previous

        thermal_previous = thermal_current - deltaH * a / (c * rho_te * rho_te * sa)
    end subroutine brick_tee_step_backward

end module brick_tee