program energy
  implicit none
  real, parameter :: mass = 3.00, gravity = 9.81, height = 4.20
  real, parameter :: velocity = 4.00
  real :: potential_energy, kinetic_energy, total_energy

  call test_energy_calculations()

contains

  real function square(x)
    real x
    square = x * x
  end function square

  subroutine test_energy_calculations()
    potential_energy = mass * gravity * height
    kinetic_energy = 0.5 * mass * square(velocity)
    total_energy = potential_energy + kinetic_energy

    print *, "Testing Energy Calculations:"
    print *, "Potential Energy: ", potential_energy
    print *, "Kinetic Energy: ", kinetic_energy
    print *, "Total Energy: ", total_energy
    print *, "Tests Completed."
  end subroutine test_energy_calculations
end program energy