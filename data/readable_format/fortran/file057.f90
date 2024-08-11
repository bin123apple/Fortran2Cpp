module noseHoover
    implicit none
    integer :: nnos
    real :: kT, gkT, gT
    real, allocatable, dimension(:) :: xi
    real, allocatable, dimension(:) :: v_xi
    real, allocatable, dimension(:) :: Q_i
    real, allocatable, dimension(:) :: G_i
    real, allocatable, dimension(:) :: omega
    logical :: debug
end module noseHoover

program testNoseHoover
    use noseHoover
    implicit none
    
    nnos = 5
    kT = 1.0
    gkT = 2.0
    gT = 3.0
    debug = .true.

    allocate(xi(nnos))
    allocate(v_xi(nnos))
    allocate(Q_i(nnos))
    allocate(G_i(nnos))
    allocate(omega(nnos))

    xi = 1.0
    v_xi = 2.0
    Q_i = 3.0
    G_i = 4.0
    omega = 5.0

    print *, 'nnos =', nnos
    print *, 'kT =', kT
    print *, 'gkT =', gkT
    print *, 'gT =', gT
    print *, 'xi(1) =', xi(1)
    print *, 'v_xi(1) =', v_xi(1)
    print *, 'Q_i(1) =', Q_i(1)
    print *, 'G_i(1) =', G_i(1)
    print *, 'omega(1) =', omega(1)
    print *, 'debug =', debug

    deallocate(xi, v_xi, Q_i, G_i, omega)
end program testNoseHoover