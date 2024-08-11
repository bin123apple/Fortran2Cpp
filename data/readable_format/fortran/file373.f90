program test_speed_of_sound
  implicit none

  ! Define the kind for double precision
  integer, parameter :: dp = selected_real_kind(15, 307)
  ! Define the specific heat ratio for air (example value)
  real(dp), parameter :: gamma = 1.4_dp
  
  real(dp) :: p, rho
  real(dp) :: expected_speed, calculated_speed
  real(dp) :: tolerance

  ! Test values
  p = 101325.0_dp   ! Pressure in Pascals
  rho = 1.225_dp    ! Density in kg/m^3 (approximately air density at sea level)
  tolerance = 1.0e-5_dp

  ! Calculate speed of sound
  calculated_speed = speed_of_sound(p, rho)
  
  ! Expected value based on the equation
  expected_speed = sqrt(gamma * p / rho)
  
  ! Check if the calculated value is within the tolerance of the expected value
  if (abs(calculated_speed - expected_speed) > tolerance) then
    print *, "Test failed for p=", p, ", rho=", rho, ", Expected:", expected_speed, ", Got:", calculated_speed
  else
    print *, "Test passed for p=", p, ", rho=", rho
  end if

contains

  ! Definition of the speed_of_sound function
  pure function speed_of_sound(p, rho) result(c)
    real(dp), intent(in) :: p, rho
    real(dp) :: c

    c = sqrt(gamma * p / rho)
  end function speed_of_sound

end program test_speed_of_sound