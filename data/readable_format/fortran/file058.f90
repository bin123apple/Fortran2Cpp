program TomographyApplication
    ! Declare custom real type and other constants
    integer, parameter :: CUSTOM_REAL = selected_real_kind(15, 307)
    integer, parameter :: MAX_STRING_LEN = 1024, NGLLX = 5, NGLLY = 5, NGLLZ = 5
    integer, parameter :: IIN = 1, IOUT = 2
    real(kind=CUSTOM_REAL), parameter :: FOUR_THIRDS = 4.0_CUSTOM_REAL / 3.0_CUSTOM_REAL
    real(kind=CUSTOM_REAL), parameter :: R_EARTH_KM = 6371.0_CUSTOM_REAL
    real(kind=CUSTOM_REAL), parameter :: GAUSSALPHA = 0.0_CUSTOM_REAL, GAUSSBETA = 0.0_CUSTOM_REAL

    ! Variables equivalent to those in tomography_par
    integer :: NSPEC, NGLOB
    real(kind=CUSTOM_REAL), dimension(:), allocatable :: x, y, z
    integer, dimension(:,:,:,:), allocatable :: ibool
    real(kind=CUSTOM_REAL) :: step_fac, step_length
    integer :: myrank, sizeprocs

    ! Example initialization
    NSPEC = 10
    NGLOB = 100
    allocate(x(NGLOB), y(NGLOB), z(NGLOB))
    x = 1.0_CUSTOM_REAL
    y = 2.0_CUSTOM_REAL
    z = 3.0_CUSTOM_REAL

    ! Example operation (simple print to demonstrate)
    call printParameters()

    ! Cleanup
    deallocate(x, y, z)

contains
    subroutine printParameters()
        print *, "NSPEC: ", NSPEC
        print *, "NGLOB: ", NGLOB
        print *, "First element of x: ", x(1)
        print *, "First element of y: ", y(1)
        print *, "First element of z: ", z(1)
    end subroutine printParameters

end program TomographyApplication