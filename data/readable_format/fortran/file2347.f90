module h_params
    implicit none
    type :: gp_type
        integer :: num_life
        real, dimension(:), allocatable :: alpha
        real :: t
        real, dimension(:), allocatable :: tau
        real :: R0
    end type gp_type
    type(gp_type) :: gp
end module h_params

module h_utils
    implicit none
contains
    real function gaus_dist(r)
        implicit none
        real, intent(in) :: r
        gaus_dist = exp(-r*r)  ! Simple Gaussian distribution for test purposes
    end function gaus_dist
end module h_utils

module h_dist_struct
    implicit none
end module h_dist_struct

! Move the gaus_decay function inside a module
module gaus_decay_mod
    use h_params
    use h_dist_struct
    use h_utils, only: gaus_dist
    implicit none
contains
    function gaus_decay(r)
        implicit none
        real, intent(in) :: r
        real :: gaus_decay

        real :: decay, gaus
        integer :: j

        decay = 0.
        do j = 1, gp%num_life
            decay = decay + gp%alpha(j) * exp(-gp%t / gp%tau(j) * (1. + (gp%R0 / r)**6))
        end do
        gaus = gaus_dist(r)
        gaus_decay = gaus * decay
    end function gaus_decay
end module gaus_decay_mod

program test_gaus_decay
    use h_params
    use gaus_decay_mod, only: gaus_decay
    implicit none
    real :: r, result

    ! Initialize test values
    gp%num_life = 2
    allocate(gp%alpha(2))
    allocate(gp%tau(2))
    gp%alpha = [0.5, 1.0]
    gp%t = 1.0
    gp%tau = [2.0, 3.0]
    gp%R0 = 1.0

    r = 2.0
    result = gaus_decay(r)

    print *, 'Result: ', result
end program test_gaus_decay