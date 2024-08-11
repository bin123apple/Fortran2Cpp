program test_openacc
  use openacc
  implicit none

  integer :: num_devices, device_num

  num_devices = acc_get_num_devices(acc_device_nvidia)

  ! Test if NVIDIA devices are available
  if (num_devices == 0) then
    print *, "No NVIDIA devices available - Test Failed"
    stop
  else
    print *, "NVIDIA devices available - Test Passed"
  end if

  ! Initialize and set device, then check device number
  call acc_init(acc_device_nvidia)
  call acc_set_device_num(0, acc_device_nvidia)
  device_num = acc_get_device_num(acc_device_nvidia)

  if (device_num == 0) then
    print *, "Device set correctly to 0 - Test Passed"
  else
    print *, "Device not set correctly - Test Failed"
  end if

  ! Shutdown and final test for multiple devices
  call acc_shutdown(acc_device_nvidia)
  if (num_devices > 1) then
    print *, "Multiple NVIDIA devices available - Test Consideration"
  else
    print *, "Single NVIDIA device available - Test Consideration"
  end if

end program test_openacc