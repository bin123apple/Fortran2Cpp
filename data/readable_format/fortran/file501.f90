! Combined Fortran file with module and test program
module MOD_Lifting_Vars
    implicit none
    public
    save
    real, allocatable :: gradPx_slave(:,:,:,:)
    real, allocatable :: gradPy_slave(:,:,:,:)
    real, allocatable :: gradPz_slave(:,:,:,:)
    real, allocatable :: gradPx_master(:,:,:,:)
    real, allocatable :: gradPy_master(:,:,:,:)
    real, allocatable :: gradPz_master(:,:,:,:)
    real, allocatable :: gradPx(:,:,:,:,:)
    real, allocatable :: gradPy(:,:,:,:,:)
    real, allocatable :: gradPz(:,:,:,:,:)
    real, allocatable :: FluxX(:,:,:,:)
    real, allocatable :: FluxY(:,:,:,:)
    real, allocatable :: FluxZ(:,:,:,:)
    logical          :: LiftingInitIsDone = .false.
end module MOD_Lifting_Vars

program test_MOD_Lifting_Vars
    use MOD_Lifting_Vars
    implicit none

    ! Test variables
    logical :: testPassed

    ! Initialize testPassed
    testPassed = .true.

    ! Allocate and initialize arrays for testing
    allocate(gradPx_slave(1,2,2,2))
    gradPx_slave = 1.0
    LiftingInitIsDone = .true.

    ! Perform checks
    if (all(gradPx_slave == 1.0) .and. LiftingInitIsDone) then
        print *, "Test Passed: gradPx_slave initialized correctly and LiftingInitIsDone is TRUE."
    else
        print *, "Test Failed."
        testPassed = .false.
    endif

    ! Deallocate to clean up
    deallocate(gradPx_slave)

    if (testPassed) then
        print *, "All tests passed successfully."
    else
        print *, "Some tests failed."
    endif
end program test_MOD_Lifting_Vars