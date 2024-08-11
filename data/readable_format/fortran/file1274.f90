module Block_Energy
    implicit none
    real, dimension(:), allocatable :: q_ns
    real, dimension(:), allocatable :: q_na
    real, dimension(:), allocatable :: dbt
    real, dimension(:), allocatable :: wind
    real, dimension(:), allocatable :: ea
    real, dimension(:), allocatable :: press
    real, dimension(:), allocatable :: mu
    real :: alphamu, beta, gmma, smooth_param
    real :: lvp, rb, rho
    real, parameter :: evap_coeff=1.5e-9, pf=0.640, pi=3.14159, rfac=304.8
end module Block_Energy

program testBlockEnergy
    use Block_Energy
    implicit none

    ! Allocate some arrays with example sizes
    allocate(q_ns(10))
    allocate(q_na(10))
    allocate(dbt(10))
    allocate(wind(10))
    allocate(ea(10))
    allocate(press(10))
    allocate(mu(10))

    alphamu = 0.5
    beta = 0.3
    gmma = 0.1
    smooth_param = 0.05
    lvp = 2500.0
    rb = 100.0
    rho = 1.225

    ! Example operation: Set and then print a value to demonstrate functionality
    q_ns = 1.0
    q_na = 2.0

    ! Check and print a simple test case to verify functionality
    if (all(q_ns == 1.0) .and. all(q_na == 2.0)) then
        print *, "Test Passed: q_ns and q_na correctly assigned."
    else
        print *, "Test Failed"
    end if

    ! Remember to deallocate arrays if they are no longer needed
    deallocate(q_ns, q_na, dbt, wind, ea, press, mu)
end program testBlockEnergy