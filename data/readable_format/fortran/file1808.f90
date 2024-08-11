module gsw_mod_kinds
    implicit none
    ! Assuming r8 represents double precision
    integer, parameter :: r8 = selected_real_kind(15, 307)
end module gsw_mod_kinds

module gsw_mod_toolbox
    use gsw_mod_kinds
    implicit none
    contains

    ! Simplified version of gsw_gibbs_ice - replace with the real implementation
    pure function gsw_gibbs_ice(nt, np, t, p) result(gibbs)
        integer, intent(in) :: nt, np
        real(r8), intent(in) :: t, p
        real(r8) :: gibbs

        ! Placeholder calculation - replace with actual gibbs function for ice
        gibbs = t + p * 0.01
    end function gsw_gibbs_ice
end module gsw_mod_toolbox

module chem_potential_module
    use gsw_mod_kinds
    use gsw_mod_toolbox, only: gsw_gibbs_ice
    implicit none
    contains

    elemental function gsw_chem_potential_water_ice(t, p) result(chem_potential)
        real(r8), intent(in) :: t, p
        real(r8) :: chem_potential

        chem_potential = gsw_gibbs_ice(0, 0, t, p)
    end function gsw_chem_potential_water_ice
end module chem_potential_module

program test_chem_potential
    use chem_potential_module
    implicit none
    real(r8) :: result
    real(r8), parameter :: test_temps(3) = [273.15_r8, 263.15_r8, 253.15_r8]
    real(r8), parameter :: test_pressures(3) = [101325.0_r8, 50000.0_r8, 200000.0_r8]
    integer :: i, j

    do i = 1, size(test_temps)
        do j = 1, size(test_pressures)
            result = gsw_chem_potential_water_ice(test_temps(i), test_pressures(j))
            print *, "T=", test_temps(i), "K, P=", test_pressures(j), "Pa, Chemical Potential=", result
        end do
    end do
end program test_chem_potential