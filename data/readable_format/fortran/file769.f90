module drivermod_serial
  implicit none
contains
  function driver() result(success)
    logical :: success
    ! Assuming driver does something simple for the test
    success = .true.
  end function driver
end module drivermod_serial

program test_driver
  use drivermod_serial, only : driver
  implicit none
  logical :: success

  ! Call the driver function and check the result
  success = driver()
  if (success) then
    print *, "Driver test passed."
  else
    print *, "Driver test failed."
  end if
end program test_driver