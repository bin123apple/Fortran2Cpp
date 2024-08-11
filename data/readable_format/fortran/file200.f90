module rpn2_module
    implicit none
contains

    subroutine rpn2_cons_update_manifold(meqn, maux, idir, iface, q, auxvec_center, auxvec_edge, flux)
        implicit none
        integer, intent(in) :: meqn, maux, idir, iface
        double precision, intent(in) :: q(meqn), auxvec_center(maux), auxvec_edge(maux)
        double precision, intent(out) :: flux(meqn)
        double precision :: urot
        integer :: m

        urot = auxvec_center(2+iface)

        do m = 1, meqn
            flux(m) = urot*q(m)
        end do
    end subroutine rpn2_cons_update_manifold

    subroutine rpn2_cons_update_zero(meqn, maux, idir, iface, q, auxvec_center, auxvec_edge, flux)
        implicit none
        integer, intent(in) :: meqn, maux, idir, iface
        double precision, intent(in) :: q(meqn), auxvec_center(maux), auxvec_edge(maux)
        double precision, intent(out) :: flux(meqn)
        integer :: m

        do m = 1, meqn
            flux(m) = 0.0
        end do
    end subroutine rpn2_cons_update_zero

end module rpn2_module

program test_rpn2
    use rpn2_module
    implicit none
    double precision, allocatable :: q(:), flux(:), auxvec_center(:), auxvec_edge(:)
    integer :: meqn, maux, idir, iface
    integer :: m

    ! Example parameters
    meqn = 3
    maux = 4
    idir = 1
    iface = 2
    allocate(q(meqn), flux(meqn), auxvec_center(maux), auxvec_edge(maux))

    ! Test data
    q = [1.0, 2.0, 3.0]
    auxvec_center = [0.1, 0.2, 0.3, 0.4]
    auxvec_edge = [0.5, 0.6, 0.7, 0.8]

    ! Test rpn2_cons_update_manifold
    call rpn2_cons_update_manifold(meqn, maux, idir, iface, q, auxvec_center, auxvec_edge, flux)

    print *, 'Testing rpn2_cons_update_manifold'
    do m = 1,meqn
        print *, 'flux(', m, ') = ', flux(m)
    end do

    ! Test rpn2_cons_update_zero
    call rpn2_cons_update_zero(meqn, maux, idir, iface, q, auxvec_center, auxvec_edge, flux)

    print *, 'Testing rpn2_cons_update_zero'
    do m = 1,meqn
        print *, 'flux(', m, ') = ', flux(m)
    end do

    deallocate(q, flux, auxvec_center, auxvec_edge)
end program test_rpn2