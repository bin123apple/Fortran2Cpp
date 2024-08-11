module configuration
    implicit none
    integer :: natoms = 0
    real, dimension(:), allocatable :: xmass
contains
    subroutine init_atoms(n)
        integer, intent(in) :: n
        integer :: i
        natoms = n
        allocate(xmass(natoms))
        do i = 1, natoms
            xmass(i) = real(i)
        end do
    end subroutine init_atoms

    subroutine print_first_atom_mass()
        if (allocated(xmass)) then
            print *, 'xmass(1):', xmass(1)
        endif
    end subroutine print_first_atom_mass
end module configuration

program test_configuration
    use configuration
    implicit none
    call init_atoms(10)
    call print_first_atom_mass
end program test_configuration