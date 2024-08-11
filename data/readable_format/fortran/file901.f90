module update_veloc_module
  implicit none
contains
  subroutine updateVelocElasticNewmark(old_velocity, acceleration, time, new_velocity)
    real, intent(in) :: old_velocity, acceleration, time
    real, intent(out) :: new_velocity
    new_velocity = old_velocity + acceleration * time
  end subroutine updateVelocElasticNewmark
end module update_veloc_module

program test_update_velocity
  use update_veloc_module
  implicit none

  real :: old_velocity = 5.0
  real :: acceleration = 2.0
  real :: time = 3.0
  real :: new_velocity

  call updateVelocElasticNewmark(old_velocity, acceleration, time, new_velocity)

  print *, "New velocity: ", new_velocity
end program test_update_velocity