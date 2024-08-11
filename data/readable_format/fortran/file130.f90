module moving_gate_mod
  implicit none
  double precision, allocatable :: xp(:), zp(:), up(:), wp(:)
  double precision :: VXgate, VZgate, dt, tgate, zmax_ini, time
  integer :: ngate_ini, ngate_end
contains
  subroutine movingGate
    integer :: i
    do i = ngate_ini, ngate_end
      if (time >= tgate) then
         xp(i) = xp(i) + VXgate * dt
         zp(i) = min(zp(i) + VZgate * dt, zmax_ini)
         up(i) = VXgate
         wp(i) = VZgate
      endif
    enddo
  end subroutine movingGate
end module moving_gate_mod

program testMovingGate
  use moving_gate_mod
  integer :: i

  ngate_ini = 1
  ngate_end = 3
  time = 5.0
  tgate = 4.0
  VXgate = 1.0
  VZgate = 2.0
  dt = 0.1
  zmax_ini = 10.0
  
  allocate(xp(ngate_end), zp(ngate_end), up(ngate_end), wp(ngate_end))
  xp = (/0.0, 0.0, 0.0/)
  zp = (/0.0, 5.0, 11.0/)
  up = (/0.0, 0.0, 0.0/)
  wp = (/0.0, 0.0, 0.0/)

  call movingGate

  print *, 'Fortran Testing MovingGate:'
  do i = 1, 3
     print *, 'Particle', i
     print *, '  xp:', xp(i)
     print *, '  zp:', zp(i)
     print *, '  up:', up(i)
     print *, '  wp:', wp(i)
  enddo

  deallocate(xp, zp, up, wp)
end program testMovingGate