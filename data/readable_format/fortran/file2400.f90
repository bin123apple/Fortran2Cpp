! E_kinetic.f90
module kinetic_module
    implicit none
    contains

    subroutine E_kinetic(KE, natom, mass, v, oldv)
        implicit none
        integer, intent(in) :: natom
        real(kind=8), intent(out) :: KE
        real(kind=8), dimension(natom), intent(in) :: mass
        real(kind=8), dimension(natom*3), intent(in) :: v, oldv
        real(kind=8) :: tmpvec(3)
        integer :: i, i1, i3

        KE = 0.0d0
        i1 = 1
        i3 = 3
        do i = 1, natom
            tmpvec = v(i1:i3) + oldv(i1:i3)
            KE = KE + mass(i) * dot_product(tmpvec, tmpvec)
            i1 = i1 + 3
            i3 = i3 + 3
        end do
        KE = KE * 0.5d0 * 0.25d0
    end subroutine E_kinetic
end module kinetic_module

program test_E_kinetic
    use kinetic_module
    implicit none
    ! Declarations for the test program
    integer :: natom
    real(kind=8) :: KE
    real(kind=8), dimension(:), allocatable :: mass, v, oldv

    ! Initialize test case
    natom = 2
    allocate(mass(natom), v(natom*3), oldv(natom*3))
    mass = (/1.0d0, 2.0d0/)
    v = (/1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0, 6.0d0/)
    oldv = (/0.5d0, 1.0d0, 1.5d0, 2.0d0, 2.5d0, 3.0d0/)

    ! Call the subroutine
    call E_kinetic(KE, natom, mass, v, oldv)
    print *, 'Test Case 1: KE = ', KE

    ! Clean up
    deallocate(mass, v, oldv)
end program test_E_kinetic