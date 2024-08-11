module turbKE
    implicit none
    ! Use real(kind=8) to specify double precision, equivalent to real*8
    real(kind=8), parameter :: ke_C_mu = 0.09
    real(kind=8), parameter :: ke_C_eps1 = 1.44
    real(kind=8), parameter :: ke_C_eps2 = 1.92
    real(kind=8), parameter :: ke_sigma = 1.3
    real(kind=8), parameter :: ke_otherstuff = 1.50d0
end module turbKE

program testTurbKE
    use turbKE
    implicit none

    ! Output the values to verify them
    print *, 'ke_C_mu = ', ke_C_mu
    print *, 'ke_C_eps1 = ', ke_C_eps1
    print *, 'ke_C_eps2 = ', ke_C_eps2
    print *, 'ke_sigma = ', ke_sigma
    print *, 'ke_otherstuff = ', ke_otherstuff

end program testTurbKE