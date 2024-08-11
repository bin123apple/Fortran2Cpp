program species_network_test
    implicit none
    
    ! Declarations
    integer, parameter :: max_species = 10
    character(len=10), dimension(max_species) :: species_names
    integer, dimension(max_species) :: atomic_numbers
    integer :: num_species = 0
    integer :: i

    ! Initialize the species network with some example data
    call init_network()

    ! Test: Output the indices of some species
    write(*,*) 'Index of Hydrogen:', find_species_index('Hydrogen')
    write(*,*) 'Index of Helium:', find_species_index('Helium')
    write(*,*) 'Index of Oxygen (expected to be 0):', find_species_index('Oxygen')

contains

    subroutine init_network()
        species_names(1) = 'Hydrogen'
        atomic_numbers(1) = 1
        species_names(2) = 'Helium'
        atomic_numbers(2) = 2
        num_species = 2
    end subroutine init_network
    
    function find_species_index(name) result(index)
        character(len=*), intent(in) :: name
        integer :: index
        integer :: i

        index = 0
        do i = 1, num_species
            if (trim(species_names(i)) == trim(name)) then
                index = i
                exit
            endif
        end do
    end function find_species_index

end program species_network_test