module precision
    implicit none
    integer, parameter :: dp = kind(1.d0)
end module precision

module mathconstants
    use precision, only: dp
    implicit none
    real(kind=dp), parameter :: pi = 3.1415926535897932384626433832795_dp
end module mathconstants

module cgsconstants
    use precision, only: dp
    implicit none
    real(kind=dp), parameter :: G_grav = 6.67430e-8_dp  ! in cgs units
end module cgsconstants

module astroconstants
    use precision, only: dp
    implicit none
    real(kind=dp), parameter :: Mpc = 3.085677581491367e24_dp  ! in cm
end module astroconstants

module cosmology_parameters
    use precision, only: dp
    use mathconstants, only: pi
    use cgsconstants, only: G_grav
    use astroconstants, only: Mpc
    implicit none

    character(len=10), parameter :: cosmo_id = "WMAP5"
    real(kind=dp), parameter :: h = 0.7
    real(kind=dp), parameter :: Omega0 = 0.279
    real(kind=dp), parameter :: Omega_B = 0.046
    real(kind=dp), parameter :: cmbtemp = 2.726
    real(kind=dp), parameter :: sigma8 = 0.817
    real(kind=dp), parameter :: n_s = 0.96
    real(kind=dp), parameter :: H0 = h * 100.0 * 1e5 / Mpc
    real(kind=dp), parameter :: rho_crit_0 = 3.0 * H0 * H0 / (8.0 * pi * G_grav)
end module cosmology_parameters

program test_cosmology
    use cosmology_parameters, only: H0, rho_crit_0, cosmo_id
    implicit none

    print *, "Cosmology ID: ", cosmo_id
    print *, "H0: ", H0
    print *, "Critical Density (rho_crit_0): ", rho_crit_0

    ! You can add more test or validation code here
end program test_cosmology