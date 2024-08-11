module energy_module
  implicit none
contains
  function calculate_potential_energy(mass, gravity, height) result(potential_energy)
    real, intent(in) :: mass, gravity, height
    real :: potential_energy

    potential_energy = mass * gravity * height
  end function calculate_potential_energy
end module energy_module

program test_energy
  use energy_module
  implicit none

  real :: mass, gravity, height, potential_energy

  mass = 3.00
  gravity = 0.81
  height = 4.20

  potential_energy = calculate_potential_energy(mass, gravity, height)

  print *, "Potential energy: ", potential_energy

  ! Simple assertion
  if (abs(potential_energy - (mass * gravity * height)) < 0.001) then
    print *, "Test passed."
  else
    print *, "Test failed."
  end if
end program test_energy