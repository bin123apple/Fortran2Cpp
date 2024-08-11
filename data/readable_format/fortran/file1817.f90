! advec_corrected.f90
program advec_corrected
  use iso_fortran_env, only: real32
  implicit none
  integer, parameter :: x_s = 12
  integer, parameter :: t_s = 100
  real(real32), parameter :: dt = 0.1
  real(real32), parameter :: dx = 0.1
  real(real32), parameter :: c = 1.0
  real(real32), parameter :: decay = 0.02
  integer, parameter :: ipos = 25
  integer :: i, j
  real(real32) :: u(x_s)
  real(real32) :: du(x_s)

  ! Initialization of u
  do i=1, x_s
    u(i) = exp( -decay * (i - ipos)**2 )
  end do

  ! Simulation loop
  do i = 1, t_s
    du(1:x_s-1) = u(2:x_s) - u(1:x_s-1)
    du(x_s) = u(1) - u(x_s)  ! Corrected for circular boundary condition

    ! Advect
    u = u - c * du / dx * dt

    if (i == 1 .or. i == t_s) then
      print *, "Iteration", i, "sum:", sum(u)
    endif
  end do
end program advec_corrected