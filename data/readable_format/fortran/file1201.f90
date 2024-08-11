module constants 

  implicit none

  real, parameter :: pi =  3.1415926535897932384626433832795028841971693993751
  complex, parameter :: ci1 = (0.,1.)
  complex, parameter :: c1 = (1.,0.)
  real, parameter :: proton_mass = 1.67262158E-27
  real, parameter :: epsilon_0 = 8.85418782E-12
  real, parameter :: unit_charge_si = 1.602176487E-19

end module constants

program test_constants
  use constants
  implicit none
  
  write(*,*) "Testing constants..."
  write(*,'(A,F30.25)') "pi: ", pi
  write(*,'(A,2F15.10)') "ci1: ", real(ci1), aimag(ci1)
  write(*,'(A,2F15.10)') "c1: ", real(c1), aimag(c1)
  write(*,'(A,E15.10)') "proton_mass: ", proton_mass
  write(*,'(A,E15.10)') "epsilon_0: ", epsilon_0
  write(*,'(A,E15.10)') "unit_charge_si: ", unit_charge_si
  
  ! Add checks and print pass/fail messages based on expected values
  ! For simplicity, we're just printing values here.

end program test_constants