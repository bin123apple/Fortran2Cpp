module dStar_crust_def
    implicit none
    ! Constants
    integer, parameter :: dp = kind(1.0d0)
    integer, parameter :: iso_name_length = 10
    integer, parameter :: crust_default_number_table_points = 2048
    real(dp), parameter :: crust_default_lgPmin = 22.0
    real(dp), parameter :: crust_default_lgPmax = 33.5
    real(dp), parameter :: crust_default_temperature = 1.0e8_dp

    type crust_table_type
        logical :: is_loaded = .false.
        integer :: nv = 0
        integer :: nisos = 0
        character(len=iso_name_length), dimension(:), allocatable :: network
        real(dp) :: lgP_min = 0.0_dp, lgP_max = 0.0_dp
        real(dp) :: T = 0.0_dp
        real(dp), dimension(:), allocatable :: lgP
        real(dp), dimension(:,:), pointer :: Y => null()
        real(dp), dimension(:), pointer :: lgRho => null()
        real(dp), dimension(:), pointer :: lgEps => null()
    end type crust_table_type

    type(crust_table_type) :: crust_table
    logical :: crust_is_initialized = .FALSE.
    character(len=256) :: crust_datadir
end module dStar_crust_def

program test_dStar_crust
    use dStar_crust_def
    implicit none

    ! Variables for testing
    integer :: i

    ! Initialize the module's table for testing
    crust_table%is_loaded = .true.
    crust_table%nv = 10
    crust_table%nisos = 3
    allocate(crust_table%network(crust_table%nisos))
    crust_table%network = ['H-1       ', 'He-4      ', 'C-12      ']
    allocate(crust_table%lgP(crust_table%nv))
    crust_table%lgP = [(22.0_dp + i, i=0, crust_table%nv-1)]

    ! Output some information to verify the setup
    print *, 'Is the crust table loaded?', crust_table%is_loaded
    print *, 'Number of isotopes:', crust_table%nisos
    do i = 1, crust_table%nisos
        print *, 'Isotope', i, ':', trim(crust_table%network(i))
    end do
end program test_dStar_crust