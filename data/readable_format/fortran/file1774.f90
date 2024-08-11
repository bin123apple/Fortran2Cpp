program test_blade
    implicit none
    integer, parameter :: ReKi = kind(1.0d0)  ! Assuming double precision
    real(ReKi), allocatable :: C(:)
    real(ReKi), allocatable :: DR(:)
    real(ReKi) :: R
    integer :: NB

    ! Allocate arrays
    allocate(C(5), DR(5))
    
    ! Test array allocation by assigning values
    C = [1.0_ReKi, 2.0_ReKi, 3.0_ReKi, 4.0_ReKi, 5.0_ReKi]
    DR = [0.5_ReKi, 1.5_ReKi, 2.5_ReKi, 3.5_ReKi, 4.5_ReKi]
    
    ! Assign values to R and NB
    R = 10.0_ReKi
    NB = 5

    ! Output to test correctness
    print *, "C:", C
    print *, "DR:", DR
    print *, "R:", R
    print *, "NB:", NB

    ! Clean up
    deallocate(C)
    deallocate(DR)
end program test_blade