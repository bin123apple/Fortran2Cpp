program calc_electron_temperature
  implicit none

  integer, parameter :: nLons = 2, nLats = 2, nAlts = 2
  real, dimension(nLons, nLats, nAlts) :: eTemperature, Temperature, TempUnit
  real, dimension(nLons, nLats, nAlts) :: Altitude_GB
  integer :: iBlock, iLon, iLat, iAlt
  real :: Alt

  ! Initialize Altitude_GB with some values
  Altitude_GB = reshape([1000.0, 1500.0, 2000.0, 2500.0, &
                         3000.0, 3500.0, 4000.0, 8000.0], shape(Altitude_GB))

  ! Assuming some values for Temperature and TempUnit for demonstration
  Temperature = 20.0
  TempUnit = 1.0

  ! Arbitrary block number for demonstration
  iBlock = 1

  ! The core logic of calc_electron_temperature
  do iLon = 1, nLons
     do iLat = 1, nLats
        do iAlt = 1, nAlts
           Alt = Altitude_GB(iLon, iLat, iAlt) / 1000.0
           if (Alt < 130.0) then
              eTemperature(iLon, iLat, iAlt) = Temperature(iLon, iLat, iAlt) * TempUnit(iLon, iLat, iAlt)
           else
              eTemperature(iLon, iLat, iAlt) = 0.0
           end if
        end do
     end do
  end do

  ! Print the eTemperature array for demonstration
  do iLon = 1, nLons
     do iLat = 1, nLats
        do iAlt = 1, nAlts
           print *, "eTemperature(", iLon, ",", iLat, ",", iAlt, ") = ", eTemperature(iLon, iLat, iAlt)
        end do
     end do
  end do

end program calc_electron_temperature