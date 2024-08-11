! ModSizeGitm.f90
module ModSizeGitm
    implicit none
    integer, parameter :: nAlts = 10
end module ModSizeGitm

! ModPlanet.f90
module ModPlanet
    implicit none
    integer, parameter :: nSpecies = 5
    integer, parameter :: nIonsAdvect = 3
    integer, parameter :: nSpeciesTotal = nSpecies + nIonsAdvect
end module ModPlanet

! ModVertical.f90
module ModVertical
    use ModSizeGitm, only: nAlts
    use ModPlanet, only: nSpecies, nIonsAdvect, nSpeciesTotal
    implicit none
    real, dimension(-1:nAlts+2) :: dAlt_F
    ! Additional variables as in your example
end module ModVertical

! MainProgram.f90
program MainProgram
    use ModVertical
    implicit none
    integer :: i

    ! Initialize dAlt_F for demonstration
    do i = -1, nAlts+2
        dAlt_F(i) = real(i)
    end do

    ! Print a test value
    print *, "Fortran dAlt_F(0): ", dAlt_F(0)
end program MainProgram